int top(stack **ptr)
{
    int a = (*ptr)->data;
    return a;
}
int pop(stack **ptr)
{
    int a = (*ptr)->data;
    stack *temp = (*ptr);
    (*ptr) = (*ptr)->next;
    free(temp);
    return a;
}
// Get top element / 获取栈顶
int top(stack **ptr)
{
    if (*ptr == NULL)
    {
        printf("Stack is empty!\n");
        return -1; // Or handle error appropriately
    }
    return (*ptr)->data;
}

// Remove top element / 弹出栈顶
int pop(stack **ptr)
{
    // 1. Safety check / 安全检查
    if (*ptr == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }

    // 2. Save the node to be deleted / 保存即将被删除的节点
    stack *temp = *ptr;

    // 3. Save the data to return / 保存数据
    int poppedData = temp->data;

    // 4. Move the head pointer to the next node / 移动头指针
    *ptr = temp->next;

    // 5. FREE THE MEMORY / 释放内存 (Crucial!)
    free(temp);

    // 6. Return data / 返回数据
    return poppedData;
}
