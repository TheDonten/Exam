template <typename Iterator, typename T>
std::pair<bool, std::pair<Iterator, Iterator>> find_two_elements_with_sum(Iterator first, Iterator last, T c) {
	Iterator f = first;
	Iterator l = last;
	std::pair<bool, std::pair<Iterator, Iterator >> p;
	p.first = false;
	p.second.first = first;
	p.second.second = last;
	while (f != l) {
		if (*f + *l == c) {
			p.first = true;
			p.second.first = f;
			p.second.second = l;
			break;
		}
		else if (*f + *l < c) {
			f++;
		}
		else if (*f + *l > c) {
			l--;
		}
	}
	return p;
}

template <typename Iterator1, typename Iterator2>
Iterator2 merge(Iterator1 first1, Iterator1 last1, Iterator1 first2, Iterator1 last2, Iterator2 output)
{
	f1 = first1;
	f2 = first2;
	while (f1 != last1 && f2 != last2)
	{
		if (*f1 < *f2)
		{
			*output = *f1;
			++f1;
		}
		else
		{
			*output = *f2;
			++f2;
		}
		++output;
	}
	while (f1 != last1)
	{
		*output = *f1;
		++f1;
		++output;
	}
	while (f2 != last2)
	{
		*output = *f2;
		++f2;
		++output;
	}
	return output;
}
