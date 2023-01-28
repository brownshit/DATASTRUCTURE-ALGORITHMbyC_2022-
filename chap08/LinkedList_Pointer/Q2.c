//		Q2.c
/*머리부터 N개 뒤에있는 노드에 대한 포인터 반환함수*/
Node* Retrive(List* list, int n) {
	Node* ptr = list->head;
	if (n >= 0) {
		for (int i = 0; i <= n; i++) {
			if (ptr->next == NULL)
				return NULL;		//다음 인자가 없는경우 NULL
			ptr = ptr->next;
		}
		return ptr;
	}
	else
		return NULL;//검색실패
}

//이에따라서 enum자료형등을 다 바꿔주긴 해야하는데 내가 뭔가 실수를 한듯,,,? 근데 논리상 이게 맞긴함
