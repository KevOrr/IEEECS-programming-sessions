;; [2017-05-22] Challenge #316 [Easy] Knight's Metric
;; https://www.reddit.com/r/dailyprogrammer/comments/6coqwk/20170522_challenge_316_easy_knights_metric/

(eval-when (:compile-toplevel :execute)
  (ql:quickload :iterate))

(defparameter *moves* '((-1 -2) (1 -2) (-1 2) (1 2)
                        (-2 -1) (2 -1) (-2 1) (2 1)))

(defclass queue ()
  ((items :type list :initarg :initial-contents)
   (back :type cons))
  (:default-initargs :initial-contents nil))

(defmethod initialize-instance :after ((q queue) &rest initargs)
  (declare (ignore initargs))
  (with-slots (items back) q
    (setf back (last items))))

(defmethod print-object ((obj queue) stream)
  (print-unreadable-object (obj stream :type t)
    (prin1 (slot-value obj 'items) stream)))

(defun queue-empty-p (q)
  (not (slot-value q 'items)))

(defun queue-pop (q)
  (with-slots (items back) q
    (prog1 (pop items)
      (when (queue-empty-p q)
        (setf back nil)))))

(defun queue-push (q item)
  (with-slots (items back) q
    (cond ((queue-empty-p q)
           (setf items (list item))
           (setf back items))
          (t
           (setf (cdr back) (cons item nil))
           (setf back (cdr back))))
    nil))

;; O(8^n)
(defun knights-moves-naive-bfs (x y)
  (declare (integer x y))
  (iter:iter outer
    (iter:with paths := (make-instance 'queue :initial-contents '(((0 0)))))
    (iter:with visited := '((0 0)))
    (iter:for path := (queue-pop paths))
    (iter:iter
      (iter:for move :in *moves*)
      (iter:for next-square := (mapcar #'+ (first path) move))
      (unless (member next-square visited)
        (when (equal next-square (list x y))
          (return-from outer
            (values (length path) (reverse (cons next-square path)))))
        (setf visited (cons next-square visited))
        (queue-push paths (cons next-square path))))))

(defparameter *final-moves*
  #2A(((0 0) (0 2)  (1 2) (1 1) (2 1))
      ((2 0) (2 -1) (0 0) (1 2) (2 0))
      ((2 1) (0 0)  (1 0) (1 1) (1 2))
      ((1 1) (2 1)  (1 1) (2 1) (3 1))
      ((1 2) (0 2)  (1 2) (1 3) (3 2))))

;; O(n)
(defun knights-moves-nonnegative (x y)
  (check-type x (integer 0))
  (check-type y (integer 0))
  (let ((path (list (list x y))))
    (loop :until (and (zerop x) (zerop y)) :do
      (cond ((and (<= 0 x 4) (<= 0 y 4))
             (setf (values x y) (values-list (aref *final-moves* y x))))
            ((<= x 0)
             (incf x)
             (decf y 2))
            ((<= y 0)
             (incf y)
             (decf x 2))
            ((> x y)
             (decf x 2)
             (decf y))
            (t
             (decf x)
             (decf y 2)))
      (push (list x y) path))
    path))

(defun knights-moves (x y)
  (declare (integer x y))
  (let ((positive-path (knights-moves-nonnegative (abs x) (abs y))))
    (cond ((and (minusp x) (minusp y))
           (mapcar (lambda (coord)
                     (list (- (first coord)) (- (second coord))))
                   positive-path))
          ((and (minusp x) (>= y 0))
           (mapcar (lambda (coord)
                     (list (- (first coord)) (second coord)))
                   positive-path))
          ((and (>= x 0) (minusp y))
           (mapcar (lambda (coord)
                     (list (- (first coord)) (- (second coord))))
                   positive-path))
          (t
           positive-path))))

(defun main ()
  (loop :for path := (knights-moves (read) (read))
        :do (format t "~A~%~A~%~%" (1- (length path)) path)))

