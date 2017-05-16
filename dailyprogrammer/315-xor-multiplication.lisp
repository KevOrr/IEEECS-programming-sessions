;; [2017-05-15] Challenge #315 [Easy] XOR Multiplication
;; For https://www.reddit.com/r/dailyprogrammer/comments/6ba9id/20170515_challenge_315_easy_xor_multiplication/

(defun xor-mult (a b)
  (declare (fixnum a b))
  (reduce #'logxor (loop :for i :from 0 :below (integer-length a)
                         :collect (ash (if (logbitp i a) b 0)
                                       i))))

(defun main ()
  (handler-case
      (loop :for a := (read)
            :for b := (read)
            :do (format t "~d@~d=~d~%" a b (xor-mult a b)))
    (end-of-file nil)))


(defun time-xor-mult (&optional (n 1000000))
  (declare (fixnum n))
  (let ((test-cases (loop :repeat n
                          :collect (list (random 1000000) (random 1000000)))))
    (time (loop :for test-case :in test-cases
                :do (destructuring-bind (a b) test-case
                      (xor-mult a b))))))

(defun commutativity-tester (&optional (n 1000000))
  (let ((test-cases (loop :repeat n
                          :collect (list (random 1000000) (random 1000000)))))
    (loop :for test-case :in test-cases
          :do (destructuring-bind (a b) test-case
                (assert (= (xor-mult a b) (xor-mult b a)))))))

(defun associativity-tester (&optional (n 1000000))
  (let ((test-cases (loop :repeat n
                          :collect (list (random 1000000) (random 1000000) (random 1000000)))))
    (loop :for test-case :in test-cases
          :do (destructuring-bind (a b c) test-case
                (assert (= (xor-mult (xor-mult a b) c) (xor-mult a (xor-mult b c))))))))
