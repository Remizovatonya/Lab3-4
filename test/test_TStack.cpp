#include "Stack.h"

#include "../gtest/gtest.h"

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> S(3));
}
