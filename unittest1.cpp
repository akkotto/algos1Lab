#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ALGOS1/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(Tests_with_int)
{
public:
	List<int> * list;

	TEST_METHOD_INITIALIZE(setup)
	{
		list = new List<int>();
	}

	TEST_METHOD_CLEANUP(cleanup)
	{
		delete list;
	}

	TEST_METHOD(push_back_first_object)
	{
		list->push_back(999999);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 999999);
	}

	TEST_METHOD(push_back)
	{
		list->push_back(98);
		list->push_back(77);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == 98 && list->at(1) == 77);
	}

	TEST_METHOD(push_front_first_object)
	{
		list->push_front(999999);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 999999);
	}

	TEST_METHOD(push_front)
	{
		list->push_front(98);
		list->push_front(77);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == 77 && list->at(1) == 98);
	}

	TEST_METHOD(pop_back_first_object)
	{
		list->push_back(98);
		list->pop_back();
		Assert::IsTrue(list->isEmpty() && list->get_size() == 0);
	}

	TEST_METHOD(pop_back_multiple_times)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(88);
		list->push_back(44);
		list->pop_back();
		list->pop_back();
		list->pop_back();
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 78);
	}

	TEST_METHOD(pop_front_first_object)
	{
		list->push_back(78);
		list->pop_front();
		Assert::IsTrue(list->isEmpty() && list->get_size() == 0);
	}

	TEST_METHOD(pop_front_multiple_times)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(88);
		list->push_back(44);
		list->pop_front();
		list->pop_front();
		list->pop_front();
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 44);
	}

	TEST_METHOD(insert_first_object)
	{
		list->push_back(78);
		list->push_back(99);

		list->insert(0, 44);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 3 && list->at(0) == 44 && list->at(1) == 78 && list->at(2) == 99);
	}

	TEST_METHOD(insert_in_the_middle_object)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(44);

		list->insert(1, 66);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 4 && list->at(0) == 78 && list->at(1) == 66 && list->at(2) == 99 && list->at(3) == 44);
	}

	TEST_METHOD(insert_tail_object)
	{
		list->push_back(78);
		list->push_back(99);

		list->insert(2, 44);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 3 && list->at(0) == 78 && list->at(1) == 99 && list->at(2) == 44);
	}

	TEST_METHOD(at)
	{
		list->push_back(78);
		list->push_back(99);

		Assert::IsTrue(!list->isEmpty() && list->at(0) == 78 && list->at(1) == 99);
	}

	TEST_METHOD(remove_head)
	{
		list->push_back(78);
		list->push_back(99);

		list->remove(0);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 99);
	}

	TEST_METHOD(remove_tail)
	{
		list->push_back(78);
		list->push_back(99);

		list->remove(1);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 78);
	}

	TEST_METHOD(remove_in_the_middle)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(44);

		list->remove(1);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == 78 && list->at(1) == 44);
	}

	TEST_METHOD(get_size)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(44);
		list->push_back(111);

		Assert::IsTrue(list->get_size() == 4);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		list->push_back(78);
		list->push_back(99);
		list->push_back(66);

		list->clear();
		Assert::IsTrue(list->isEmpty());
	}

	TEST_METHOD(set)
	{
		list->push_back(78);
		list->push_back(99);

		list->set(1, 110);
		Assert::IsTrue(list->at(0) == 78 && list->at(1) == 110);
	}
};

TEST_CLASS(Tests_with_double)
{
public:
	List<double> * list;

	TEST_METHOD_INITIALIZE(setup)
	{
		list = new List<double>();
	}

	TEST_METHOD_CLEANUP(cleanup)
	{
		delete list;
	}

	TEST_METHOD(push_back)
	{
		list->push_back(98.679697);
		list->push_back(77.344612);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == 98.679697 && list->at(1) == 77.344612);
	}

	TEST_METHOD(push_front)
	{
		list->push_front(98.679697);
		list->push_front(77.344612);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(1) == 98.679697 && list->at(0) == 77.344612);
	}

	TEST_METHOD(pop_front)
	{
		list->push_front(98.679697);
		list->push_front(77.3446126);
		list->push_front(77.344612);
		list->pop_front();
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == 77.3446126);
	}

	TEST_METHOD(insert)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);

		list->insert(1, 22.124178);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 3 && list->at(0) == 98.679697 && list->at(1) == 22.124178 && list->at(2) == 77.3446126);
	}

	TEST_METHOD(at)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);

		Assert::IsTrue(!list->isEmpty() && list->at(0) == 98.679697 && list->at(1) == 77.3446126);
	}

	TEST_METHOD(remove)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);

		list->remove(1);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 1 && list->at(0) == 98.679697);
	}

	TEST_METHOD(get_size)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);
		list->push_back(66.124612);

		Assert::IsTrue(list->get_size() == 3);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);
		list->push_back(66.124612);

		list->clear();
		Assert::IsTrue(list->isEmpty());
	}

	TEST_METHOD(set)
	{
		list->push_back(98.679697);
		list->push_back(77.3446126);
		list->push_back(66.124612);

		list->set(1, 66.12416278);
		Assert::IsTrue(list->at(0) == 98.679697 && list->at(1) == 66.12416278 && list->at(2) == 66.124612);
	}
};

TEST_CLASS(Tests_with_class)
{
public:
	class Class
	{
	public:
		double x;
		double y;
		double z;

		Class(double x = 18274.12431, double y = -124.12489, double z = 1248.12122)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		~Class() {};

		const bool operator== (const Class& class1)
		{
			return (x == class1.x && y == class1.y && z == class1.z);
		}
	};


	List<Class> * list;
	Class class1;
	Class class2;
	Class class3;

	TEST_METHOD_INITIALIZE(setup)
	{
		list = new List<Class>();
		class2 = Class(124512.123121, -81245.4121, 124841.124124);
		class3 = Class(-124124.96790124, 9712422.124421, 472190.00000124);
	}

	TEST_METHOD_CLEANUP(cleanup)
	{
		delete list;
	}

	TEST_METHOD(push_back)
	{
		list->push_back(class1);
		Assert::IsTrue(list->isEmpty() == 0 && list->get_size() == 1 && list->at(0) == class1);
	}

	TEST_METHOD(push_front)
	{
		list->push_front(class1);
		Assert::IsTrue(list->isEmpty() == 0 && list->get_size() == 1 && list->at(0) == class1);
	}

	TEST_METHOD(pop_back)
	{
		list->push_back(class1);
		list->push_back(class2);
		list->push_back(class3);

		list->pop_back();
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == class1 && list->at(1) == class2);
	}

	TEST_METHOD(pop_front)
	{
		list->push_back(class1);
		list->push_back(class2);
		list->push_back(class3);

		list->pop_front();
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == class2 && list->at(1) == class3);
	}

	TEST_METHOD(insert)
	{
		list->push_back(class1);
		list->push_back(class2);

		list->insert(1, class3);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 3 && list->at(0) == class1 && list->at(1) == class3 && list->at(2) == class2);
	}

	TEST_METHOD(at)
	{
		list->push_back(class1);
		list->push_back(class3);
		list->push_back(class2);

		Assert::IsTrue(list->at(0) == class1 && list->at(1) == class3 && list->at(2) == class2);
	}

	TEST_METHOD(remove)
	{
		list->push_back(class1);
		list->push_back(class3);
		list->push_back(class2);

		list->remove(1);
		Assert::IsTrue(!list->isEmpty() && list->get_size() == 2 && list->at(0) == class1 && list->at(1) == class2);
	}

	TEST_METHOD(get_size)
	{
		list->push_back(class1);
		list->push_back(class2);
		list->push_back(class3);

		Assert::IsTrue(list->get_size() == 3);
	}

	TEST_METHOD(clear_and_isEmpty)
	{
		list->push_back(class1);
		list->push_back(class2);
		list->push_back(class3);

		list->clear();
		Assert::IsTrue(list->isEmpty());
	}

	TEST_METHOD(set)
	{
		list->push_back(class1);
		list->push_back(class2);

		list->set(1, class3);
		Assert::IsTrue(list->at(0) == class1 && list->at(1) == class3);
	}
};

TEST_CLASS(Exceptions)
{
public:
	List<int> * list;

	TEST_METHOD_INITIALIZE(setup)
	{
		list = new List<int>();
	}

	TEST_METHOD_CLEANUP(cleanup)
	{
		delete list;
	}

	TEST_METHOD(pop_in_empty_list)
	{
		try
		{
			list->pop_back();
		}
		catch (logic_error message)
		{
			Assert::AreEqual("The list is empty", message.what());
		}

		try
		{
			list->pop_front();
		}
		catch (logic_error message)
		{
			Assert::AreEqual("The list is empty", message.what());
		}
	}

	TEST_METHOD(insert_with_invalid_argument)
	{
		try
		{
			list->insert(-1, 1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}

		try
		{
			list->insert(2, 1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}
	}

	TEST_METHOD(remove_with_invalid_argument)
	{
		list->push_back(10);
		try
		{
			list->remove(-1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}

		try
		{
			list->remove(1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}
	}

	TEST_METHOD(at_with_invalid_argument)
	{
		list->push_back(10);
		try
		{
			list->at(-1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}

		try
		{
			list->at(1);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}
	}

	TEST_METHOD(set_with_invalid_argument)
	{
		list->push_back(10);
		try
		{
			list->set(-1, 12);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}

		try
		{
			list->set(1, 12);
		}
		catch (invalid_argument message)
		{
			Assert::AreEqual("Index out of range", message.what());
		}
	}
};