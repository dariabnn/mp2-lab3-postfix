#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, can_create_postfix)
{
    ASSERT_NO_THROW(TPostfix p);
}

TEST(TPostfix, can_create_postfix_with_given_string)
{
    ASSERT_NO_THROW(TPostfix p("a-b"));
}

TEST(TPostfix, can_get_infix)
{
    TPostfix pos("a-b");
    EXPECT_EQ("a-b", pos.GetInfix());
}

TEST(TPostfix, can_get_postfix_1)
{
    TPostfix pos("a-b");
    EXPECT_EQ("ab-", pos.ToPostfix());
}

TEST(TPostfix, can_get_postfix_2)
{
    TPostfix pos("a+b/c*(d+h)-b");
    EXPECT_EQ("abc/dh+*+b-", pos.ToPostfix());
}

TEST(TPostfix, can_get_postfix_3)
{
    TPostfix pos("(a+b)*c-d");
    EXPECT_EQ("ab+c*d-", pos.ToPostfix());
}

TEST(TPostfix, can_get_postfix_4)
{
    TPostfix pos("-(c*d+a)/(b*e)");
    EXPECT_EQ("cd*a+be*/-", pos.ToPostfix());
}

TEST(TPostfix, can_get_postfix_5)
{
    TPostfix pos("-(b*(d+a))/(c*e)");
    EXPECT_EQ("bda+*ce*/-", pos.ToPostfix());
}


TEST(TPostfix, can_get_operations)
{
    TPostfix pos("a-b");
    string post;
    post = pos.GetInfix();
    EXPECT_EQ(true, pos.ChechOper(post[1]));
}

TEST(TPostfix, can_get_operand)
{
    TPostfix pos("a-b");
    string post;
    post = pos.GetInfix();
    EXPECT_EQ(false, pos.ChechOper(post[0]));
}

TEST(TPostfix, can_get_priority)
{
    TPostfix pos("a-b");
    string post;
    post = pos.GetInfix();
    EXPECT_EQ(1, pos.GetPriority(post[1]));
}
