#include "Queue.h"

#include "../gtest/gtest.h"

TEST(TStack, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> Q(3));
}