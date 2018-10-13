defmodule BinarySearch do
  require Integer

  def find(_, []) do
    raise ArgumentError, message: "Input list is empty"
  end

  def find(target, list) when is_integer(target) do
    middle = compute_middle(list)
    find(target, list, middle)
  end

  def find(_target, _) do
    raise ArgumentError, message: "Target is not integer"
  end

  defp find(target, list, middle) do
    cond do
      Enum.at(list, middle) < target ->
        find(target, list, middle + 1)
      Enum.at(list, middle) > target ->
        find(target, list, middle - 1)
      true ->
        middle
    end
  end

  defp compute_middle(list) do
    list |> Enum.count |> Kernel./(2) |> Float.floor |> round
  end
end
