#include <string>

class Node
{
  public:
    std::string value;

    Node(const std::string &val, Node *previous = nullptr, Node *next = nullptr)
        : value{val}, prev{previous}, succ{next}
    {
    }

    /*!
     * @brief insert a `Node` before this node.
     * @param node the `Node` to insert.
     * @return pointer to the inserted node, `this` if `node` NULL.
     */
    Node *prepend(Node *node)
    {
        if (!node)
            return nullptr; // Insert nothing.

        node->succ = this;
        node->prev = this->prev;
        if (this->prev)
            this->prev->succ = node;

        this->prev = node;
        return node;
    }

    /*!
     * @brief insert a `Node` after this node.
     * @param node the `Node to insert.
     * @return pointer to the inserted node, `this` if `node` NULL.
     */
    Node *append(Node *node)
    {
        if (!node)
            return nullptr; // Insert nothing.

        node->succ = this->succ;
        node->prev = this;
        if (this->succ)
            this->succ->prev = node;

        this->succ = node;
        return node;
    }

    /*!
     * @brief remove a `Node` from a list.
     * @return pointer to the successor node.
     */
    Node *remove()
    {
        if (this->succ)
            this->succ->prev = this->prev;

        if (this->prev)
            this->prev->succ = this->succ;

        return this->succ;
    }

    /*!
     * @brief return the `Node` n nodes from this node.
     * @param steps how many nodes to iterate, +ve to move forward, -ve to
     * move backwards.
     * @return the nth `Node`, NULL if end of list is reached.
     */
    Node *advance(long long int steps) const
    {
        Node *p = const_cast<Node *>(this);

        while (steps > 0 && p)
        {
            p = p->succ;
            --steps;
        }

        while (steps < 0 && p)
        {
            p = p->prev;
            ++steps;
        }

        return p;
    }

    Node *next() const { return succ; }

    Node *previous() const { return prev; }

  private:
    Node *prev;
    Node *succ;
};

class List
{
  public:
    List(Node *head) : head{head} {}
    Node *find(const std::string &s);
    const Node *find(const std::string &s) const;

  private:
    Node *head;
};

int main(void) { return (0); }
