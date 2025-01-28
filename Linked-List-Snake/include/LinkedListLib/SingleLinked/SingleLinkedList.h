#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedListLib/Node.h"
#include "LinkedListLib/LinkedList.h"

namespace LinkedListLib
{
	namespace SingleLinked
	{
		class SingleLinkedList : public LinkedList
		{
		protected:
			virtual Node* createNode() override;

			void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);

			sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);

			void updateNodePosition();

		public:
			SingleLinkedList();
			~SingleLinkedList();


			void insertNodeAtTail() override;
			void insertNodeAtIndex(int index);
			void insertNodeAtHead() override;
			void insertNodeAtMiddle() override;
			void insertNodeAtIndex(int index, Node* new_node);

			void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);

			void updateNodeDirection(Direction direction_to_set);

			void render();

			bool processNodeCollision();

			Node* getHeadNode();

			void removeNodeAtTail() override;
			void removeNodeAtHead() override;
			std::vector<sf::Vector2i> getNodesPosition();
			void initializeNode(Node* new_node, Node* reference_node, Operation operation);
			void removeNodeAtMiddle() override;
			void removeNodeAt(int index) override;
			void removeNodeAtIndex(int index);
			void removeAllNodes() override;
			void removeHalfNodes() override;

			Direction getReverseDirection(Direction reference_direction);

			void shiftNodesAfterRemoval(Node* cur_node);

			int findMiddleNode();

			Node* findNodeAtIndex(int index);

			Direction reverse() override;
			void reverseNodeDirections();
		};
	}
}