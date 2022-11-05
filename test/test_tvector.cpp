#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, throws_when_create_vector_with_zero_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(0));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	const int size = 2;
	TDynamicVector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
	}
	TDynamicVector<int> v1(v);
	EXPECT_EQ(v, v1);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	const int size = 2;
	int i;
	TDynamicVector<int> v(size);
	for (i = 0; i < size; i++)
	{
		v[i] = i;
	}
	TDynamicVector<int> v1(v);
	for (i = 0; i < v1.size(); i++)
	{
		v1[i] = i + 5;
	}
	EXPECT_EQ(0, v[0]);
	EXPECT_EQ(1, v[1]);
	EXPECT_NE(0, v1[0]);
	EXPECT_NE(1, v1[1]);
}

TEST(TDynamicVector, can_convert_array_to_vector)
{
	const int size = 2;
	int arr[size] = { 1, 2 };
	TDynamicVector<int> v(arr, size);

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(-2) = 10);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(5);
	ASSERT_ANY_THROW(v.at(5) = 10);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	const int size = 2;
	TDynamicVector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
	}
	v = v;
	EXPECT_EQ(0, v[0]);
	EXPECT_EQ(1, v[1]);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size);
	for (int i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	v2 = v1;
	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	const int size = 5, size1 = 10;
	TDynamicVector<int> v(size), v1(size1);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
	}
	v1 = v;
	EXPECT_EQ(5, v1.size());
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	const int size1 = 2, size2 = 5;
	TDynamicVector<int> v1(size1), v2(size2);
	int i;
	for (i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (i = 0; i < size2; i++)
	{
		v2[i] = i + 5;
	}
	v2 = v1;
	EXPECT_EQ(v2, v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	const int size = 2;
	TDynamicVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
		v1[i] = i;
	}
	EXPECT_EQ(true, v == v1);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	const int size = 2;
	TDynamicVector<int> v(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
	}
	EXPECT_EQ(true, v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	const int size1 = 5, size2 = 2;
	TDynamicVector<int> v1(size1), v2(size2);
	int i;
	for (i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (i = 0; i < size2; i++)
	{
		v2[i] = v1[i];
	}
	EXPECT_EQ(false, v1 == v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	const int size = 2;
	TDynamicVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i;
	}
	v1 = v + 1;
	EXPECT_EQ(1, v1[0]);
	EXPECT_EQ(2, v1[1]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	const int size = 2;
	TDynamicVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i + 1;
	}
	v1 = v - 1;
	EXPECT_EQ(0, v1[0]);
	EXPECT_EQ(1, v1[1]);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	const int size = 2;
	TDynamicVector<int> v(size), v1(size);
	for (int i = 0; i < size; i++)
	{
		v[i] = i + 1;
	}
	v1 = v * 2;
	EXPECT_EQ(2, v1[0]);
	EXPECT_EQ(4, v1[1]);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size), v3;
	int i;
	for (i = 0; i < size; i++)
	{
		v1[i] = i;
	}
	for (i = 0; i < size; i++)
	{
		v2[i] = i + 1;
	}
	v3 = v1 + v2;
	EXPECT_EQ(1, v3[0]);
	EXPECT_EQ(3, v3[1]);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	const int size1 = 2, size2 = 5;
	TDynamicVector<int> v1(size1), v2(size2), v3;
	int i;
	for (i = 0; i < size1; i++)
	{
		v1[i] = i;
	}
	for (i = 0; i < size2; i++)
	{
		v2[i] = i + 1;
	}
	ASSERT_ANY_THROW(v3 = v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size), v3;
	int i;
	for (i = 0; i < size; i++)
	{
		v1[i] = i + 1 + i * 2;
	}
	for (i = 0; i < size; i++)
	{
		v2[i] = i + 1;
	}
	v3 = v1 - v2;
	EXPECT_EQ(0, v3[0]);
	EXPECT_EQ(2, v3[1]);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	const int size1 = 2, size2 = 5;
	TDynamicVector<int> v1(size1), v2(size2), v3;
	int i;
	for (i = 0; i < size1; i++)
	{
		v1[i] = i + 1 + i * 2;
	}
	for (i = 0; i < size2; i++)
	{
		v2[i] = i + 1;
	}
	ASSERT_ANY_THROW(v3 = v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	const int size = 2;
	TDynamicVector<int> v1(size), v2(size);
	int scal, i;
	for (i = 0; i < size; i++)
	{
		v1[i] = i + 1;
	}
	for (i = 0; i < size; i++)
	{
		v2[i] = i + 2;
	}
	scal = v1 * v2;
	EXPECT_EQ(8, scal);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	const int size1 = 2, size2 = 5;
	TDynamicVector<int> v1(size1), v2(size2);
	int scal, i;
	for (i = 0; i < size1; i++)
	{
		v1[i] = i + 1;
	}
	for (i = 0; i < size2; i++)
	{
		v2[i] = i + 2;
	}
	ASSERT_ANY_THROW(scal = v1 * v2);
}
