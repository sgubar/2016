IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
      if (SLCountList(const IntList *aList) < anIndex ||aList == NULL || aNewNode ==NULL)// перевырка чи буде входити комірка комірка яку ми хочемо додати у існуючий список
            return NULL;
      if (anIndex == 0 && aList->head == NULL && aList->tail == NULL )// перевірка чи існує загалі список
            aList->head = aNewNode;

    else
    {
        IntNode *theNode = SLNodeAtIndex(aList, anIndex);
        aNewNode-> theNode = theNode->nextNode;
        IntNode *theNode = SLNodeAtIndex(aList, anIndex-1);//знаходимо індекс(номер) комірки попередньої до тої, що ми додали
        theNode-> nextNode = aNewNode;//створюємо звязок між нодою що була на місці тієї що ми додали і тієї що ми додали
        aList->count += 1;

        return aNewNode;
    }

    IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

    if (SLCountList(const IntList *aList) < anIndex ||aList == NULL || aNewNode ==NULL)//аналогічно як у першій функції робимо перевірки
    return NULL;
      if (anIndex == 0 && aList->head == NULL && aList->tail == NULL )
            aList->head = aNewNode;
            else
            {
              IntNode *theNode = SLNodeAtIndex(aList, anIndex-1);//знаходимо адресу комірки, яка знаходиться перед тією, яку ми хочемо видалити.
              theNode->nextNode=theNode->nextNode->nextNode;//задаємо що попередня нода вказує на наступну ноду тієї, яку ми видалили
            }
