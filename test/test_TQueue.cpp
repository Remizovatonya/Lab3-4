#include "Queue.h"

#include "../gtest/gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> Q(3));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> Q(-2));
}

TEST(TQueue, can_create_copied_queue)
{
    TQueue<int> Q(5);
    ASSERT_NO_THROW(TQueue<int> Q1(Q));
}

TEST(TQueue, copied_queue_is_equal_to_source_one)
{
    TQueue<int> Q(3), Q1(Q);
    EXPECT_EQ(Q, Q1);
}

TEST(TQueue, can_assign_matrix_to_itself)
{
    TQueue<int> Q(5);
    ASSERT_NO_THROW(Q = Q);
}

TEST(TQueue, can_assign_matrices_of_equal_size)
{
    TQueue<int> Q(5), Q1(5);
    ASSERT_NO_THROW(Q = Q1);
}


TEST(TQueue, can_assign_matrices_of_different_size)
{
    TQueue<int> Q(5), Q1(3);
    ASSERT_NO_THROW(Q = Q1);
}

TEST(TQueue, compare_equal_empty_queue_return_true)
{
    TQueue<int> Q(5), Q1(5);
    ASSERT_EQ(Q == Q1, true);
}

TEST(TQueue, compare_equal_queue_with_elements_return_true)
{
    TQueue<int> Q(2), Q1(2);
    Q.Push(7);
    Q.Push(4);
    Q1.Push(7);
    Q1.Push(4);
    ASSERT_EQ(Q == Q1, true);
}

TEST(TQueue, compare_queue_with_itself_return_true)
{
    TQueue<int> Q(5);
    ASSERT_EQ(Q == Q, true);
}

TEST(TQueue, queue_with_different_size_are_not_equal)
{
    TQueue<int> Q(5), Q1(3);
    ASSERT_EQ(Q == Q1, false);
}

TEST(TQueue, queue_with_different_ind_are_not_equal)
{
    TQueue<int> Q(5), Q1(5);
    Q.Push(9);
    ASSERT_EQ(Q == Q1, false);
}

TEST(TQueue, queue_with_different_end_are_not_equal)
{
    TQueue<int> Q(5), Q1(5);
    Q.Push(9);
    Q.Push(8);
    Q1.Push(0);
    ASSERT_EQ(Q == Q1, false);
}

TEST(TQueue, queue_with_different_count_are_not_equal)
{
    TQueue<int> Q(5), Q1(5);
    Q.Push(9);
    Q.Push(8);
    Q1.Push(0);
    Q1.Push(1);
    Q1.Push(2);
    ASSERT_EQ(Q == Q1, false);
}

TEST(TQueue, queue_with_different_elements_are_not_equal)
{
    TQueue<int> Q(5), Q1(5);
    Q.Push(9);
    Q1.Push(8);
    ASSERT_EQ(Q == Q1, false);
}

TEST(TQueue, can_push_element_in_not_full_queue)
{
    TQueue<int> Q(5);
    ASSERT_NO_THROW(Q.Push(2));
}

TEST(TQueue, cant_push_element_in_full_queue)
{
    TQueue<int> Q(3);
    Q.Push(1);
    Q.Push(2);
    Q.Push(3);
    ASSERT_ANY_THROW(Q.Push(4));
}

TEST(TQueue, can_get_element_of_not_empty_queue)
{
    TQueue<int> Q(5);
    Q.Push(9);
    ASSERT_NO_THROW(Q.Get());
}

TEST(TQueue, cant_get_element_of_empty_queue)
{
    TQueue<int> Q(3);
    ASSERT_ANY_THROW(Q.Get());
}

TEST(TQueue, get_return_element_pointed_by_ind)
{
    TQueue<int> Q(5);
    Q.Push(7);
    Q.Push(4);
    EXPECT_EQ(7, Q.Get());
}

TEST(TQueue, queue_with_null_count_is_empty_and_return_true)
{
    TQueue<int> Q(5);
    ASSERT_EQ(Q.IsEmpty(), true);
}

TEST(TQueue, queue_with_not_null_count_is_not_empty_and_return_false)
{
    TQueue<int> Q(5);
    Q.Push(9);
    ASSERT_EQ(Q.IsEmpty(), false);
}

TEST(TQueue, queue_with_count_equal_length_is_full_and_return_true)
{
    TQueue<int> Q(3);
    Q.Push(9);
    Q.Push(8);
    Q.Push(7);
    ASSERT_EQ(Q.IsFull(), true);
}

TEST(TQueue, queue_with_count_not_equal_length_is_not_full_and_return_false)
{
    TQueue<int> Q(5);
    Q.Push(9);
    ASSERT_EQ(Q.IsFull(), false);
}

TEST(TQueue, can_get_length)
{
    TQueue<int> Q(5);
    EXPECT_EQ(5, Q.GetLength());
}

TEST(TQueue, can_get_ind)
{
    TQueue<int> Q(5);
    Q.Push(7);
    EXPECT_EQ(0, Q.GetInd());
}

TEST(TQueue, can_get_end)
{
    TQueue<int> Q(5);
    Q.Push(7);
    Q.Push(8);
    EXPECT_EQ(2, Q.GetEnd());
}

TEST(TQueue, can_get_count)
{
    TQueue<int> Q(5);
    Q.Push(7);
    Q.Push(8);
    Q.Push(9);
    EXPECT_EQ(3, Q.GetCount());
}
