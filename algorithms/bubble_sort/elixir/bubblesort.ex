defmodule BubbleSort do
  def sort([]),  do: []
  def sort(list) do
    round = swap(list)
    cond do
      round == list -> list
      true -> sort(round)
    end
  end

  defp swap([head | []]), do: [head]
  defp swap([head | [second | tail]]) do
    cond do
      head < second -> [head | swap([second | tail])]
      true  -> [second | swap([head | tail])]
    end
  end
end
