#include "binary_trees.h"
/**
 * createQueue - Creates a queue
 * Return: Pointer to the created queue
 */
Queue *createQueue()
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));

	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

/**
 * enqueue - Adds a node to the queue
 * @queue: Pointer to the queue
 * @treeNode: Pointer to the binary tree node
 */
void enqueue(Queue *queue, binary_tree_t *treeNode)
{
	QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));

	newNode->treeNode = treeNode;
	newNode->next = NULL;

	if (queue->rear == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
}

/**
 * dequeue - Removes a node from the queue
 * @queue: Pointer to the queue
 * Return: Pointer to the removed node
*/
binary_tree_t *dequeue(Queue *queue)
{
	if (queue->front == NULL)
	{
		return (NULL);
	}

	QueueNode *tempNode = queue->front;
	binary_tree_t *treeNode = tempNode->treeNode;

	queue->front = queue->front->next;

	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(tempNode);
	return (treeNode);
}

/**
 * isQueueEmpty - Checks if the queue is empty
 * @queue: Pointer to the queue
 * Return: 1 if the queue is empty, 0 otherwise
 */
int isQueueEmpty(Queue *queue)
{
	return (queue->front == NULL);
}
