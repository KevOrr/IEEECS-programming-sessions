(format t "~A" (reduce #'* (list (read) (read)) :key (lambda (x) (ceiling (/ x 2)))))
