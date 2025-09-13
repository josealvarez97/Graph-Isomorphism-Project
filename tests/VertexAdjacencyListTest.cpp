// tests/VertexAdjacencyListTest.cpp
#include <gtest/gtest.h>
// #include "../GraphIsomorphisim_Version_1.0/VertexAdjacencyList.h"

// TEST(CVertexAdjacencyListTest, InitiallyEmpty) {
//     CVertexAdjacencyList list;
//     EXPECT_EQ(list.Size(), 0);  // Newly constructed list should have size 0:contentReference[oaicite:7]{index=7}.
//     EXPECT_EQ(list.head, nullptr);  // Head pointer should be null on empty list.
//     EXPECT_FALSE(list.IsAnElement(42));  // No element should be found in empty list:contentReference[oaicite:8]{index=8}.
// }

// TEST(CVertexAdjacencyListTest, AddSingleElement) {
//     CVertexAdjacencyList list;
//     bool result = list.Add(5);
//     EXPECT_TRUE(result);                   // Add should return true on success:contentReference[oaicite:9]{index=9}.
//     EXPECT_EQ(list.Size(), 1);             // Size should increment to 1.
//     EXPECT_NE(list.head, nullptr);         // Head should no longer be null.
//     EXPECT_EQ(list.head->value, 5);        // The head node's value should be the added element:contentReference[oaicite:10]{index=10}.
//     EXPECT_TRUE(list.IsAnElement(5));      // Element 5 should be found in the list:contentReference[oaicite:11]{index=11}.
//     EXPECT_EQ(list.ElementAtIndex(0), 5);  // Index 0 should return the first element.
// }

// TEST(CVertexAdjacencyListTest, AddMultipleElements) {
//     CVertexAdjacencyList list;
//     list.Add(1);
//     list.Add(2);
//     list.Add(3);
//     EXPECT_EQ(list.Size(), 3);                 // Three elements added, size should be 3:contentReference[oaicite:12]{index=12}.
//     // Check that elements are in the order inserted:
//     EXPECT_EQ(list.ElementAtIndex(0), 1);
//     EXPECT_EQ(list.ElementAtIndex(1), 2);
//     EXPECT_EQ(list.ElementAtIndex(2), 3);
//     // All added elements should be found:
//     EXPECT_TRUE(list.IsAnElement(1));
//     EXPECT_TRUE(list.IsAnElement(2));
//     EXPECT_TRUE(list.IsAnElement(3));
//     // A non-existing element should not be found:
//     EXPECT_FALSE(list.IsAnElement(99));
// }

// TEST(CVertexAdjacencyListTest, ElementAtIndexOutOfRange) {
//     CVertexAdjacencyList list;
//     list.Add(10);
//     list.Add(20);
//     EXPECT_EQ(list.Size(), 2);
//     // Index equal to size or beyond should return -1 to indicate invalid index:contentReference[oaicite:13]{index=13}.
//     EXPECT_EQ(list.ElementAtIndex(2), -1);
//     EXPECT_EQ(list.ElementAtIndex(5), -1);
// }

// TEST(CVertexAdjacencyListTest, SetAndGetVertexValue) {
//     CVertexAdjacencyList list;
//     list.SetVertexValue(7);
//     EXPECT_EQ(list.Value(), 7);  // Value() should return the vertex id set by SetVertexValue:contentReference[oaicite:14]{index=14}:contentReference[oaicite:15]{index=15}.
// }

// TEST SIMPLE TEST
TEST(HelloWorldTest, BasicAssertions) {
  // Expect two strings to be equal.
  EXPECT_STREQ("Hello", "Hello");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}