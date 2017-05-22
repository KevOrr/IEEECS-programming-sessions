;; [2017-05-22] Challenge #316 [Easy] Knight's Metric
;; https://www.reddit.com/r/dailyprogrammer/comments/6coqwk/20170522_challenge_316_easy_knights_metric/

(defparameter *moves* '((-1 -2) (1 -2) (-1 2) (1 2)
                        (-2 -1) (2 -1) (-2 1) (2 1)))

(defun count-kights-moves (x y)
  (declare (integer x y))
  (loop :with paths := '(((0 0)))
        :with visited := '((0 0))
        :while paths
        :for path := (pop paths)
        :if (equal (first path) (list x y))
          :return (values (1- (length path)) (reverse path))
        :do (loop :for move :in *moves*
                  :for next-square := (mapcar #'+ (first path) move)
                  :unless (member next-square visited)
                    :do (setf visited (cons next-square visited))
                        (setf paths (append paths (list (cons next-square path)))))))

(defun main ()
  (loop
    (multiple-value-bind (distance path) (count-kights-moves (read) (read))
      (format t "~A~{~%~{~A ~}~}~%" distance path))))
