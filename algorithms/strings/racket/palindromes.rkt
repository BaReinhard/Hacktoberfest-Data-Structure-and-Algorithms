#lang racket
(require test-engine/racket-tests)

;String -> Boolean
; produce true if palindrome
(check-expect (palindrome? "") true)
(check-expect (palindrome? "cat") false)
(check-expect (palindrome? "tat") true)

(define (palindrome? str)
  (string=? str (reverse-string str)))

;String -> String
;reverse string
(check-expect (reverse-string "") "")
(check-expect (reverse-string "cat") "tac")

(define (reverse-string str)
  (cond [(string=? str "") ""]
        [else (string-append (reverse-string (substring str 1 )) (substring str 0 1))]))