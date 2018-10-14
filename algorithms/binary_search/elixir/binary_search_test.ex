# how to run tests:
# elixir -r binary_search.ex binary_search_test.ex 
ExUnit.start

defmodule BinarySearchTest do
  use ExUnit.Case

  test "finds element in odd list" do
    assert BinarySearch.find(2, [1,2,3,4,5]) == 1
  end

  test "finds element in even list" do
    assert BinarySearch.find(4, [1,2,3,4,5,6]) == 3
  end

  test "returns nil when element is not found" do
    assert BinarySearch.find(8, [1,2,3,4,5,6]) == nil
  end

  test "raises an error when list is empty" do
    assert_raise ArgumentError, fn ->
      BinarySearch.find(2, [])
    end
  end

  test "raises an error when target is not integer" do
    assert_raise ArgumentError, fn ->
      BinarySearch.find("one", [1,2,3])
    end
  end

 end
