(loop :repeat (read) :do
  (let ((n (read)))
    (declare ((unsigned-byte 32) n))
    (format t "~A~%" (* 1/2 n (- n 1)))))
