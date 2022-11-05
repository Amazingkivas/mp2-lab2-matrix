#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_zero_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(0));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	TDynamicMatrix<int> m1(m);
	EXPECT_EQ(m[0][0], m1[0][0]);
	EXPECT_EQ(m[0][1], m1[0][1]);
	EXPECT_EQ(m[1][0], m1[1][0]);
	EXPECT_EQ(m[1][1], m1[1][1]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	TDynamicMatrix<int> m1(m);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			m1[i][j] = 5;
			EXPECT_NE(5, m[i][j]);
			EXPECT_EQ(5, m1[i][j]);
		}
	}
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);

	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;

	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(0, -1) = 10);
	ASSERT_ANY_THROW(m.at(-1, 0) = 10);
	ASSERT_ANY_THROW(m.at(-1, -1) = 10);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(0, 2) = 10);
	ASSERT_ANY_THROW(m.at(2, 0) = 10);
	ASSERT_ANY_THROW(m.at(2, 2) = 10);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	m = m;
	EXPECT_EQ(1, m[0][0]);
	EXPECT_EQ(2, m[0][1]);
	EXPECT_EQ(0, m[1][0]);
	EXPECT_EQ(3, m[1][1]);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size), m2(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	m2 = m1;
	EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 2, size2 = 5;
	TDynamicMatrix<int> m1(size1), m2(size2);
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = i; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	m2 = m1;
	EXPECT_EQ(2, m2.size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 2, size2 = 3;
	TDynamicMatrix<int> m1(size1), m2(size2);
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = i; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = i; j < size2; j++)
		{
			m2[i][j] = i + j + 5;
		}
	}
	m2 = m1;
	EXPECT_EQ(m2, m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size), m2(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m1[i][j] = i + j + 1;
			m2[i][j] = i + j + 1;
		}
	}
	EXPECT_EQ(true, m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	EXPECT_EQ(true, m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 3, size2 = 2;
	TDynamicMatrix<int> m1(size1), m2(size2);
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = i; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = i; j < size2; j++)
		{
			m2[i][j] = m1[i][j];
		}
	}
	EXPECT_EQ(false, m2 == m1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size), m2(size), m3;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m1[i][j] = i + j + 1;
			m2[i][j] = i + j;
		}
	}
	m3 = m1 + m2;
	EXPECT_EQ(1, m3[0][0]);
	EXPECT_EQ(3, m3[0][1]);
	EXPECT_EQ(0, m3[1][0]);
	EXPECT_EQ(5, m3[1][1]);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	const int size1 = 3, size2 = 2;
	TDynamicMatrix<int> m1(size1), m2(size2), m3;
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = i; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = i; j < size2; j++)
		{
			m2[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(m3 = m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size), m2(size), m3;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m1[i][j] = i + j + 1;
			m2[i][j] = i + j;
		}
	}
	m3 = m1 - m2;
	EXPECT_EQ(1, m3[0][0]);
	EXPECT_EQ(1, m3[0][1]);
	EXPECT_EQ(0, m3[1][0]);
	EXPECT_EQ(1, m3[1][1]);
}

TEST(TDynamicMatrix, cant_subtract_matrices_with_not_equal_size)
{
	const int size1 = 3, size2 = 2;
	TDynamicMatrix<int> m1(size1), m2(size2), m3;
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = i; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = i; j < size2; j++)
		{
			m2[i][j] = i + j;
		}
	}
	ASSERT_ANY_THROW(m3 = m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_scalar_by_matrix)
{
	const int size = 2;
	TDynamicMatrix<int> m(size), m1;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	m1 = m * 2;
	EXPECT_EQ(2, m1[0][0]);
	EXPECT_EQ(4, m1[0][1]);
	EXPECT_EQ(0, m1[1][0]);
	EXPECT_EQ(6, m1[1][1]);
}

TEST(TDynamicMatrix, can_multiply_vector_by_matrix_with_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m(size);
	TDynamicVector<int> v(size), v1;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = i; j < size; j++)
		{
			m[i][j] = i + j + 1;
		}
		v[i] = i + 1;
	}
	v1 = m * v;
	EXPECT_EQ(5, v1[0]);
	EXPECT_EQ(6, v1[1]);
}

TEST(TDynamicMatrix, cant_multiply_vector_by_matrix_with_not_equal_size)
{
	const int size_m = 2, size_v = 5;
	TDynamicMatrix<int> m(size_m);
	TDynamicVector<int> v(size_v), v1;
	int i, j;
	for (i = 0; i < size_m; i++)
	{
		for (j = i; j < size_m; j++)
		{
			m[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size_v; i++)
	{
		v[i] = i + 1;
	}
	ASSERT_ANY_THROW(v1 = m * v);
}

TEST(TDynamicMatrix, can_multiply_matrices_with_equal_size)
{
	const int size = 2;
	TDynamicMatrix<int> m1(size), m2(size), m3;
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			m1[i][j] = i + j + 1;
			m2[i][j] = i + j + 2;
		}
	}
	m3 = m1 * m2;
	EXPECT_EQ(8, m3[0][0]);
	EXPECT_EQ(11, m3[0][1]);
	EXPECT_EQ(13, m3[1][0]);
	EXPECT_EQ(18, m3[1][1]);
}

TEST(TDynamicMatrix, cant_multiply_matrices_with_not_equal_size)
{
	const int size1 = 3, size2 = 2;
	TDynamicMatrix<int> m1(size1), m2(size2), m3;
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size1; j++)
		{
			m1[i][j] = i + j + 1;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2; j++)
		{
			m2[i][j] = i + j + 2;
		}
	}
	ASSERT_ANY_THROW(m3 = m1 * m2);
}
