module DataStructures.Stack.LinearStack 
  ( Stack
  , empty
  , isEmpty
  , push 
  , pop
  , top
  ) where

import Data.List(intercalate)

data Stack a = Empty | Node a (Stack a)


empty :: Stack a
empty =  Empty

isEmpty :: Stack a -> Bool
isEmpty Empty =  True
isEmpty _     =  False

push :: a -> Stack a -> Stack a
push x s =  Node x s

top :: Stack a -> a
top Empty      =  error "top on empty stack"
top (Node x s) =  x

pop :: Stack a -> Stack a
pop Empty      =  error "pop on empty stack"
pop (Node x s) =  s

-- Showing a stack

instance (Show a) => Show (Stack a) where
  show s = "Stack(" ++ intercalate "," (aux s) ++ ")"
    where
	aux Empty      =  []
        aux (Node x s) =  show x : aux s

-- Stacks equality

instance (Eq a) => Eq (Stack a) where
  Empty      == Empty        =  True
  (Node x s) == (Node x' s') =  x==x' && s==s'
  _          == _            =  False
