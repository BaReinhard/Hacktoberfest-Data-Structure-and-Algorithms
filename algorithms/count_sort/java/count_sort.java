	public int[] count_sort(int[] a)
	{
		int[] result = new int[a.length];
		int[] count = new int[a.length];
		for (int i = 0; i < a.length; i++)
		{
			count[i] = 0;
		}
		for (int i = 0; i < a.length-1; i++)
		{
			for (int j = i + 1; j < a.length; j++)
			{
				if (a[i] < a[j])
					count[j] = count[j] + 1;
				else
					count[i] = count[i] + 1;
			}
		}
		for (int i = 0; i < a.length; i++)
		{
			result[count[i]] = a[i];
		}
		return result;
	}