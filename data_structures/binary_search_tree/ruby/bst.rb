module JLancar
  BSTNode = Struct.new(:value, :left_node, :right_node)

  class BinaryTree
    attr_accessor :root_node

    def initialize(root_val = nil)
      @root_node = BSTNode.new(root_val, nil, nil) unless root_val.nil?
    end

    def search(value)
      return nil if @root_node.nil?
      return search_at_node(@root_node, value)
    end

    def search_at_node(tree_node, value)
      return nil if tree_node.nil?

      return tree_node if value == tree_node.value
      return search_at_node(tree_node.left_node, value) if value < tree_node.value
      return search_at_node(tree_node.right_node, value)
    end

    def insert(value)
      new_node = BSTNode.new(value, nil, nil)
      @root_node = new_node and return if @root_node.nil?

      insert_at_node(@root_node, new_node)
    end

    def insert_at_node(tree_node, new_node)
      tree_node = new_node and return if tree_node.nil?

      return tree_node if tree_node.value == new_node.value

      if new_node.value < tree_node.value
        return insert_at_node(tree_node.left_node, new_node) unless tree_node.left_node.nil?
        return tree_node.left_node = new_node
      end

      return insert_at_node(tree_node.right_node, new_node) unless tree_node.right_node.nil?
      tree_node.right_node = new_node
    end

    def traverse(&block)
      traverse_at_node(@root_node, &block)
    end

    def traverse_at_node(node, &block)
      return if node.nil?
      traverse_at_node(node.left_node, &block)
      yield node.value if block_given?
      traverse_at_node(node.right_node, &block)
    end
  end
end

########
# TEST #
########
test = JLancar::BinaryTree.new
test.insert(5)
test.insert(5)
test.insert(4)
test.insert(7)
test.insert(15)
test.insert(1)
test.insert(2)

p test.search(5)
p test.search(4)
p test.search(7)
p test.search(7)
p test.search(17) # should return nil
p test.search(15)
p test.search(1)
p test.search(2)

test.traverse{|x| puts x }
