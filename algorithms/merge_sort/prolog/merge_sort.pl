/*
	This "function" takes in two lists and outputs a list created through a merge sort of the two inputted lists
	Syntax: merge(+List1, +List2, ?X)
*/

merge([], [], []).
merge(Item1, [], Item1).
merge([], Item2, Item2).

merge([Item1],[Item2], [Item1, Item2]) :- Item1 =< Item2.
merge([Item1],[Item2], [Item2, Item1]) :- Item2 =< Item1.

merge(ListA, ListB, MergedList) :-  ListA = [HeadA | TailA], ListB = [HeadB | _], HeadA =< HeadB, MergedList = [HeadA | NewMerged], merge(TailA, ListB, NewMerged).
merge(ListA, ListB, MergedList) :-  ListA = [HeadA | _], ListB = [HeadB | TailB], HeadB =< HeadA, MergedList = [HeadB | NewMerged], merge(ListA, TailB, NewMerged).
