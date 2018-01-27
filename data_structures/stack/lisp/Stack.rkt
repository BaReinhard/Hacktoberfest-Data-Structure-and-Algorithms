(define (make-stack)

  ;backing structure
  (define arr '())
  (define length 0)
  (define temp '())

  ;size method
  (define (size)
    length)

  ;print method
  (define (print)
    (display arr))

  ;pop method: removes the head and returns it
  (define (pop)
    (set! temp (car arr))
    (set! arr (cdr arr))
    temp)

  ;push method: puts x at the head
  (define (push x)
    (set! arr (cons x arr)))

  ;method to get method from user
  (define (dispatch method)
    (cond ((eq? method 'size) size)
          ((eq? method 'pop) pop)
          ((eq? method 'print) print)
          ((eq? method 'push) push)
          (else (lambda() (display "Unknown Stack Request")(display method)(newline)))))

  dispatch)

;how to use
(define (testing)
  (define stack (make-stack))
  ((stack 'push) 0)
  ((stack 'push) 1)
  ((stack 'push) 2)
  ((stack 'print))(newline)
  ((stack 'pop))
  ((stack 'print))(newline)
  )

(testing)
  
  