; calculates all prime numbers from two up to the given 'max'
(defun sieve (max)
  (let ((bit-vector (make-array max :initial-element 1 :element-type 'bit)))
  (loop for i from 2 upto (isqrt max) do
    (loop for j from i
      for index = (* i j)
      until (>= index max) do
      (setf (sbit bit-vector index) 0)))
  (loop for i from 2 below (length bit-vector)
    unless (zerop (sbit bit-vector i)) collect i)))


(pprint "Example of the Sieve of Eratosthenes.")
(pprint "Enter the number to which you want to know the prime numbers:")
(defvar max1 (read))
(pprint (sieve max1))
