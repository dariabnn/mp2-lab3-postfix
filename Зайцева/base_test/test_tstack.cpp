#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
    ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_too_large_stack)
{
    ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
    ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, can_create_copied_stack)
{
    TStack<int> st(10);

    ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack, copied_stack_has_its_own_memory)
{
    TStack<int> st0(4);
    TStack<int> st1(st0);
    st1.push(1);
    st0.push(2);

    EXPECT_NE(st0.get_element(), st1.get_element());
}

TEST(TStack, can_add_and_get_element)
{
    TStack<int> st(4);
    st.push(5);
    EXPECT_EQ(5, st.get_element());
}

TEST(TStack, throws_when_full_stack)
{
    TStack<int> st(1);
    st.push(1);
    EXPECT_EQ(true, st.full());
}

TEST(TStack, throws_when_add_element_to_full_stack)
{
    TStack<int> st(1);
    st.push(1);
    ASSERT_ANY_THROW(st.push(1));
}

TEST(TStack, throws_when_empty_stack)
{
    TStack<int> st(1);
    EXPECT_EQ(true, st.empty());
}

TEST(TStack, throws_when_delete_element_from_empty_stack)
{
    TStack<int> st(1);
    ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, can_delete_and_get_element)
{
    TStack<int> st(4);
    st.push(5);
    EXPECT_EQ(5, st.pop());
}
