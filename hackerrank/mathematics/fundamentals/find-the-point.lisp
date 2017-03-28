(defun rot-point (p q)
  (list (- (* 2 (first q)) (first p))
        (- (* 2 (second q)) (second p))))

(loop :repeat (read) :do
  (format t "~{~A~^ ~}~%" (rot-point (list (read) (read))
                                     (list (read) (read)))))
