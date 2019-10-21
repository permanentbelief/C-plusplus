namespace lth
{
	template<class T>
	struct __list_node // �ڵ�
	{
		__list_node<T>* _next; // node* _next;
		__list_node<T>* _prev; // node* _prev;
		T _data;

		__list_node(const T& x = T()) //���캯��              �ڵ�Ĺ��캯��(_list_node(const T&x = T())
			:_data(x)
			, _next(nullptr)
			, _prev(nullptr)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator //			typedef	__list_iterator<T,T&,T*> iterator							��������� ��
	{
		typedef __list_node<T> node;
		typedef __list_iterator<T, Ref, Ptr> Self;

		node* _node; //Ҳ���� __list_node<T>* _node;                     ������ָ��

		__list_iterator(node* node)         //                         ���������캯��(��ָ��)
			:_node(node)
		{}

		Ref operator*() // ��������         Ref�� T&
		{
			return _node->_data;
		}

		Ptr operator->() // �Զ�������     Ptr: T*
		{
			return &_node->_data;
		}


		Self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		Self operator++(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			__list_iterator<T> tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		// it1 !=  it2
		bool operator!=(const Self& it)
		{
			return _node != it._node;
		}

		bool operator==(const Self& it)
		{
			return _node == it._node;
		}
	};

	template<class T> //��ģ��  ����list
	class list
	{
		typedef __list_node<T> node;
	public:
		//������ͨiterator������ ��const_iterator������
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		const_iterator begin() const //__list_iterator<T, const T&, const T*>
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const //__list_iterator<T, const T&, const T*>
		{
			return const_iterator(_head);
		}

		iterator begin() //_list_iterator<T,T&,T*>
		{
			return iterator(_head->_next);
		}

		iterator end()//_list_iterator<T,T&,T*>
		{
			return iterator(_head);
		}

		// copy(l)
		/* list(const list<T>& l)
		{
		//�Լ�д��
		_head = new node;//���Բ�Ҫ�βΣ����� ��������ʲô��node
		_head->_next =_head;
		_head->_prev =_head;
		const_iterator it = l.begin();
		while(it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/
		//clear (��ͷ���ȫ���ͷ�)
		/* void clear()
		{
		iterator it = l.begin();
		while(it != end())
		{
		it = earse(it);
		}
		}
		// l2 = l1
		list <T>&(const list<T>& l)
		{
		clear();
		const_iterator it = l.begin();
		while(it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/

		list(const list<T>& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;

			//const_iterator it = l.begin();
			auto it = l.begin();
			while (it != l.end())
			{
				push_back(*it);
				++it;
			}
		}

		// l2 = l1
		/*list<T>& operator=(const list<T>& l)
		{
		this->clear();

		auto it = l.begin();
		while (it != l.end())
		{
		push_back(*it);
		++it;
		}
		}*/
		// l2 = l1
		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}

		list()
		{
			_head = new node(T());
			_head->_next = _head;
			_head->_prev = _head;
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		//void push_back(const T& x)
		//{
		//	node* tail = _head->_prev;
		//	node* newnode = new node(x);

		//	// head ... tail newnode 
		//	tail->_next = newnode;
		//	newnode->_prev = tail;
		//	newnode->_next = _head;
		//	_head->_prev = newnode;
		//}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* newnode = new node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		iterator erase(iterator pos)
		{
			node* cur = pos._node;
			assert(cur != _head);

			node* prev = cur->_prev;
			node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return iterator(next);
		}

	private:
		node* _head;
	};

	void print_list(const list<int>& l)
	{
		list<int>::const_iterator it = l.begin();
		while (it != l.end())
		{
			//*it = 10; // it.operator*() = 10;
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}


	void test_list1()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		print_list(l);

		list<int>::iterator it = l.begin();
		while (it != l.end())
		{
			if (*it % 2 == 0)
			{
				it = l.erase(it);
			}
			else
			{
				++it;
			}
		}

		print_list(l);
	}

	struct Date
	{
		int _year = 1900;
		int _month = 1;
		int _day = 1;
	};

	void test_list2()
	{
		list<Date> l;
		l.push_back(Date());
		l.push_back(Date());

		//list<Date>::iterator it = l.begin();
		auto it = l.begin();
		while (it != l.end())
		{
			//cout << *it << endl;
			cout << it->_year << "-" << it->_month << "-" << it->_day << endl;
			++it;
		}

		//int* p *p
		//Date* p p->_year;
	}

	void test_list3()
	{
		list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);
		l.push_back(4);
		//print_list(l);

		list<int> copy = l;
		l.push_back(5);

		print_list(copy);
		print_list(l);
	}
}