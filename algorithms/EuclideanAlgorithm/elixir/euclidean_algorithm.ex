defmodule EuclideanAlgorithm do
  @moduledoc """
  Implementation of the Euclidean algorithm to find
  the greatest common divisor of two positive integers.
  """
  def gcd(a, b)
    when is_integer(a) and is_integer(b) and
         a > 0 and b > 0 do
    case a > b do
      true  -> compute_gcd(a, b)
      false -> compute_gcd(b, a)
    end
  end

  def gcd(_a, _b) do
    raise ArgumentError, message: "Input is not valid"
  end

  defp compute_gcd(a, 0), do: a
  defp compute_gcd(a, b) do
    remainder = rem(a, b)
    compute_gcd(b, remainder)
  end
end
