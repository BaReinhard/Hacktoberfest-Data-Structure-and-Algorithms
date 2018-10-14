defmodule BinarySearch do
  require Integer

  def find(_, []) do
    raise ArgumentError, message: "Input list is empty"
  end

  def find(target, list) when is_integer(target) do
    min = 0
    max = Enum.count(list) - 1
    middle = compute_middle(min, max)
    find(target, list, middle, min, max)
  end

  def find(_target, _) do
    raise ArgumentError, message: "Target is not integer"
  end

  defp find(target, list, middle, min, max) do
    cond do
      Enum.at(list, middle) == target ->
        middle
      max < min ->
        nil
      Enum.at(list, middle) < target ->
        min = middle + 1
        max = max - 1
        middle = compute_middle(min, max)
        find(target, list, middle, min, max)
      Enum.at(list, middle) > target ->
        max = middle - 1
        middle = compute_middle(min, max)
        find(target, list, middle, min, max)
      true ->
        nil
    end
  end

  defp compute_middle(min, max) do
    min..max |> Enum.count |> Kernel./(2) |> Float.floor |> round
  end
end
