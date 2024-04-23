## Henry Madriles
## CS101L 8:30am
## Week 15 Program
## 
## Describe the problem: Have to create a unit test for the functions in another file and make sure they return the outputs we expect.
##
## Algorithm: Unit tests are important because we want to make sure our program will output what we expect it to.
## If we make changes to our program, then our tests can test it with the same inputs and make sure it still outputs what we want.
## It also makes finding errors much easier.
##
## Importance of Unit tests: We will be implementing unit tests in our programs in the future so it is a very useful skill to have to test our programs and make sure they work.

import unittest
import Grades
import math

class Grade_Test(unittest.TestCase):
    def test_total_returns_total_of_list(self):
        result = Grades.total([1, 10, 22])
        self.assertEqual(result, 33, "The total function should return 33")
    def test_total_returns_0(self):
        result = Grades.total([])
        self.assertEqual(result, 0, "The total function should return 0")
    def test_average_one(self):
        result = Grades.average([2,5,9])
        self.assertAlmostEqual(result, 5.33333, 3)
    def test_average_two(self):
        result = Grades.average([2,15,22,9])
        self.assertAlmostEqual(result, 12.0000, 4)
    def test_average_returns_nan(self):
        result = Grades.average([])
        self.assertIs(result, math.nan, "The average function should return math.nan") 
    def test_median_one(self):
        result = Grades.median([2,5,1])
        self.assertEqual(result,2, "The median function returns 2")
    def test_median_two(self):
        result = Grades.median([5,2,1,3])
        self.assertEqual(result, 2.5, "The median function returns the middle of 2 and 3")
    def test_median_empty_list(self):
        with self.assertRaises(ValueError):
            result = Grades.median([])

unittest.main()    



    
