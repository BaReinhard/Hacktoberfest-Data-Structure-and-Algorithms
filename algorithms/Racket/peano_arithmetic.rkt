#lang racket

(require racket/contract)

(define (zero? n)
  (eq? n 'zero))

(define (nat? x)
  (cond
    [(zero? x) #t]
    [(pair? x) (and (eq? (first x) 'succ) (nat? (second x)))]
    [else #f]))

(define (succ n)
  (list 'succ n))

(define (pred n)
  (if (zero? n) 'zero (second n)))

(define zero 'zero)
(define one (succ zero))
(define two (succ one))
(define three (succ two))
(define four (succ three))
(define five (succ four))
(define six (succ five))
(define seven (succ six))
(define eight (succ seven))
(define nine (succ eight))
(define ten (succ nine))

(define (plus m n)
  (if (zero? m)
      n
      (succ (plus (pred m) n))))

(define (mult m n)
  (if (eq? m 'zero)
      'zero
      (plus n (mult (pred m) n))))

(define (ltnat? m n)
  (cond
    [(zero? n) #f]
    [(zero? m) #t]
    [else (ltnat? (pred m) (pred n))]))

(define (sub m n)
  (cond
    [(zero? n) m]
    [(ltnat? m n) "Undifined"]
    [else (sub (pred m) (pred n))]
  ))

(define (div m n)
  (cond
    [(zero? n) 'zero]
    [(zero? m) 'zero]
    [(equal? one n) m]
    [(equal? one m) 'zero]
    [(equal? m n) one]
    [else (succ (div (sub m n) n))])
  )
(define (rem m n)
  (cond
    [(zero? m) 'zero]
    [(equal? n one) 'zero]
    [(ltnat? m n) m]
    [else (rem (sub m n) n)])
  )

(define (gcd m n)
  (if (equal? 'zero n)
      m
      (gcd n (rem m n))
      ))
