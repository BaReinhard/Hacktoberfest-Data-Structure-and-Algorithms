-module(mergesort).
-export([mergesort/1]).

mergesort([]) -> [];
mergesort([Element]) -> [Element];
mergesort(List) ->
  {List1, List2} = lists:split(trunc(length(List)/2), List), merge(mergesort(List1), mergesort(List2)).

merge([], List) -> List;
merge(List, []) -> List;
merge([Head1|Tail1], [Head2|Tail2]) ->
  if
    Head1 < Head2 -> [Head1 | merge(Tail1, [Head2|Tail2])];
    true -> [Head2 | merge([Head1|Tail1], Tail2)]
  end.
