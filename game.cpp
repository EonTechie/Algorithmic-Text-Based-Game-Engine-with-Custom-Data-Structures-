/**
 * Developed by EonTechie
 * Repository: https://github.com/EonTechie
 */


#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iterator>
#include "doublelinklist.h" // Includes the custom library for doubly linked list functionality.
#include "objects.h" // Includes the custom library for game objects and game state management.

using namespace std;

// I Defined a generic Stack data structure template using a doubly linked list for data storage.
template <typename T>
struct Stack {  
    private:
        DoublyList<T> data; // I used Doubly linked list to store stack elements.
    public:
        void push(T& e); // Pushes an element to the top of the stack.
        T pop(); // Removes and returns the top element from the stack.
        T& top(); // Returns a reference to the top element without removing it.
        int elemcount = 0; // Keeps track of the number of elements in the stack.
};

// Implementation of the push method to add a new element to the stack.
template <typename T>
void Stack<T>::push(T& new_element) {
    data.addFront(new_element); // Inserts the new element at the front of the list.
    elemcount++; // Increments the element count.
}

// Implementation of the pop method to remove and return the top element of the stack.
template <typename T>
T Stack<T>::pop() {
    T result = data.head->data; // Retrieves the data from the head of the list (top of the stack).
    data.removeFront(); // Removes the front element of the list.
    elemcount--; // Decrements the element count.
    return result; // Returns the removed element.
}

// Implementation of the top method to return a reference to the top element.
template <typename T>
T& Stack<T>::top() {
    return data.head->data; // Returns the data from the head of the list (top of the stack).
}

// Function to create and initialize an empty GameState.
GameState createEmptyGameState() {
    GameState newState;
    newState.create_init_state(); // Initializes the GameState with default values.
    return newState;
}

// Function to copy the contents from one GameState to another.
void copyGameState(GameState& state1, GameState& state2) {
    state2.lose = state1.lose; // Copies the win/lose status from state1 to state2.
    state2.win = state1.win; // Copies the win status.
    state2.room_id = state1.room_id; // Copies the current room ID.

    // Clears current inventory and rooms before copying from state1.
    auto currentInventory = state2.inventory.head;
    while (currentInventory != NULL) {
        auto nextInventory = currentInventory->next;
        delete currentInventory; // Deletes inventory items from state2.
        currentInventory = nextInventory;
    }
    state2.inventory.head = state2.inventory.tail = NULL;
    state2.inventory.elemcount = 0;

    auto currentRooms = state2.rooms.head;
    while (currentRooms != NULL) {
        auto nextRooms = currentRooms->next;
        delete currentRooms; // Deletes rooms from state2.
        currentRooms = nextRooms;
    }
    state2.rooms.head = state2.rooms.tail = NULL;
    state2.rooms.elemcount = 0;

    // Copies inventory and rooms from state1 to state2.
    auto otherCurrentInventory = state1.inventory.head;
    while (otherCurrentInventory != NULL) {
        state2.inventory.addBack(otherCurrentInventory->data); // Copies inventory.
        otherCurrentInventory = otherCurrentInventory->next;
    }

    auto otherCurrentRooms = state1.rooms.head;
    while (otherCurrentRooms != NULL) {
        state2.rooms.addBack(otherCurrentRooms->data); // Copies rooms.
        otherCurrentRooms = otherCurrentRooms->next;
    }
}


int main() {
    Stack<GameState> states; // Initializes a stack to store game states for DFS exploration.
    GameState activeState;
    activeState.create_init_state(); // Creates and initializes the starting game state.
    states.push(activeState); // Pushes the initial game state onto the stack.

    // Main loop continues until a win condition is met.
    while (!activeState.win) {
        // Iterates over all possible actions defined in the game.

        for(int i = 1; i < 6; i++) {

            int total_object_number = activeState.inventory.elemcount + activeState.rooms.get(activeState.room_id)->room_objects.elemcount;
            
            // Iterates over all objects that can interact with the actions.
            for(int j = 0; j < total_object_number; j++) {
                cout << "Action: " << i << " Object: " << j << endl;

                GameState potentialState = createEmptyGameState(); // Creates a potential new game state for exploration.
                copyGameState(activeState, potentialState); // Copies the current state to the potential new state for exploration.

                int isThereAnyChange = potentialState.advance(i, j); // Applies the action and checks for changes in the game state.
                
                if(isThereAnyChange == 0) {
                    // No significant change occurred, continue exploring other actions.
                } else if(isThereAnyChange > 0) {
                    cout << "Action: " << i << " Object: " << j << " has led to a change." << endl;

                    // A positive change occurred, push this new state onto the stack for further exploration.
                    states.push(potentialState);
                    if(states.top().win) {
                        // A winning state is achieved, break the loop to end the game exploration.
                        break;
                    }
                } else if (isThereAnyChange < 0) {
                    // A losing state is encountered, no further exploration needed for this path.
                }
            }
            if(states.top().win) {
                // If a winning condition has been detected in the current path, exit the exploration loop.
                break;
            }
        }

            // If the current exploration path didn't lead to a win, backtrack by popping the last state.
            if (!states.top().win) {
            activeState = states.pop(); 
            } else {
                break; // A winning state has been found, end the exploration.
            }
    }

    // Exploration ends when a winning condition is met or all possible paths have been exhausted.
    return 0;
}
