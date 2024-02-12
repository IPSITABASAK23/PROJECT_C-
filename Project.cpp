#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

class Booking {
public:
    int roomNumber;
    string host;
    string startTime;
    string endTime;
    int chairs;

    Booking(int rn, string h, string st, string et, int c)
        : roomNumber(rn), host(h), startTime(st), endTime(et), chairs(c) {}
};

class BookingList {
    struct ListNode {
        Booking booking;
        ListNode* next;
        ListNode(Booking b) : booking(b), next(nullptr) {}
    };

    ListNode* head;

public:
    BookingList() : head(nullptr) {}

    
    void addBooking(Booking booking) {
        ListNode* newNode = new ListNode(booking);
        newNode->next = head;
        head = newNode;
    }

    
    void displayBookings() {
        ListNode* current = head;
        while (current != nullptr) {
            cout << "Room: " << current->booking.roomNumber << ", Host: " << current->booking.host << endl;
            current = current->next;
        }
    }

    ~BookingList() {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class RoomBookingSystem {
    BookingList bookings;
    stack<Booking> history;
    queue<Booking> bookingRequests;

public:
    
    void bookRoom(Booking booking) {
        bookings.addBooking(booking);
        history.push(booking);
        cout << "Room " << booking.roomNumber << " booked successfully." << endl;
    }

    
    void processBookings() {
        while (!bookingRequests.empty()) {
            bookRoom(bookingRequests.front());
            bookingRequests.pop();
        }
    }

    
    void addBookingRequest(Booking booking) {
        bookingRequests.push(booking);
    }

    
    void displayAllBookings() {
        bookings.displayBookings();
    }
};

int main() {
    RoomBookingSystem system;

    
    system.addBookingRequest(Booking(100, "Ipsita", "09:00", "11:00", 10));
    system.addBookingRequest(Booking(101, "Sneha", "10:00", "12:00", 8));

    
    system.processBookings();

    
    system.displayAllBookings();

    return 0;
}