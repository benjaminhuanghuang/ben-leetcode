from data_structure.list_node import ListNode

def delete_node(node):
    node.val = node.next.val
    node.next = node.next.next


head = ListNode(0)