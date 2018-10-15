# how to run tests:
# elixir -r euclidean_algorithm.ex euclidean_algorithm_test.ex 
ExUnit.start

defmodule EuclideanAlgorithmTest do
  use ExUnit.Case

  test "finds gcd of 270 and 192" do
    assert EuclideanAlgorithm.gcd(270, 192) == 6
  end

  test "finds gcd of 45 and 210" do
    assert EuclideanAlgorithm.gcd(45, 210) == 15
  end

  test "raises an error when input is not positive integer" do
    assert_raise ArgumentError, fn ->
      EuclideanAlgorithm.gcd(-1, 0)
    end
  end
 
end
