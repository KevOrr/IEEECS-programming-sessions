(let* ((x (read-line))
       (e (read)))
  (loop :for i :across x :do
    (princ (mod (+ e (digit-char-p i)) 10))))
