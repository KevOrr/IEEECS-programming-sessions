(let* ((n (read))
       (high (read))
       (n-high 0)
       (low high)
       (n-low 0))
  (loop :repeat (- n 1) :do
    (let ((next (read)))
      (cond
        ((> next high)
         (setf high next)
         (incf n-high))

        ((< next low)
         (setf low next)
         (incf n-low)))))
  (format t "~D ~D" n-high n-low))
