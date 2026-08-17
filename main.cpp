#include <iostream> 
#include <fstream> 
#include <string> 
#include <map> 
#include <algorithm> 
#include <windows.h> 
#include <ctime> 
#include <vector> 
#include <cstdlib> 
using namespace std; 
class ChatBot { 
private: 
map<string, string> responses; 
string username; 
public: 
// Console Color 
void setColor() { 
system("color 0A"); 
} 
// Typing Animation 
void typingAnimation(string text) { 
cout << "Bot : "; 
for (char c : text) { 
cout << c; 
Sleep(30); 
15 
} 
cout << endl; 
} 
// Convert to lowercase 
string toLower(string text) { 
transform(text.begin(), 
text.end(), 
text.begin(), 
::tolower); 
return text; 
} 
// Load data from file 
void loadResponses() { 
ifstream file("data.txt"); 
if (!file) { 
cout << "data.txt file not found!\n"; 
return; 
} 
string question, answer; 
while (getline(file, question, '|') && 
getline(file, answer)) { 
responses[question] = answer; 
} 
file.close(); 
} 
// Save chat history 
void saveHistory(string userText, 
string botText) { 
16 
ofstream history("history.txt", 
ios::app); 
history << "User : " 
<< userText << endl; 
history << "Bot  : " 
<< botText << endl; 
history << "----------------------" 
<< endl; 
history.close(); 
} 
// Current Time 
string getTime() { 
time_t now = time(0); 
char* dt = ctime(&now); 
return string(dt); 
} 
// Random Greeting 
string randomGreeting() { 
vector<string> greetings = { 
"Hello student!", 
"Hi there!", 
"Welcome!", 
"Nice to meet you!" 
}; 
int index = rand() % greetings.size(); 
return greetings[index]; 
17 
} 
// Joke Feature 
string tellJoke() { 
vector<string> jokes = { 
"Why do programmers prefer dark mode? Because light attracts bugs!", 
"Why did the computer get cold? Because it left its Windows open!", 
"Why was the math book sad? Because it had too many problems!" 
}; 
int index = rand() % jokes.size(); 
return jokes[index]; 
} 
// Calculator 
string calculator(string input) { 
int a, b; 
char op; 
sscanf(input.c_str(), 
"calculate %d %c %d", 
&a, &op, &b); 
switch (op) { 
case '+': 
return "Answer = " + 
to_string(a + b); 
case '-': 
return "Answer = " + 
to_string(a - b); 
case '*': 
return "Answer = " + 
18 
to_string(a * b); 
case '/': 
if (b != 0) 
return "Answer = " + 
to_string(a / b); 
else 
return "Cannot divide by zero."; 
default: 
return "Invalid calculation."; 
} 
} 
// Generate Response 
string getResponse(string userInput) { 
string lowerInput = 
toLower(userInput); 
// Greetings 
if (lowerInput == "hello" || 
lowerInput == "hi") { 
return randomGreeting(); 
} 
// Time 
if (lowerInput.find("time") 
!= string::npos) { 
return "Current Time : " 
+ getTime(); 
} 
// Joke 
19 
if (lowerInput.find("joke") 
!= string::npos) { 
return tellJoke(); 
} 
// Sad mood 
if (lowerInput.find("sad") 
!= string::npos) { 
return "I hope things get better soon."; 
} 
// Calculator 
if (lowerInput.find("calculate") 
!= string::npos) { 
return calculator(lowerInput); 
} 
// Smart keyword matching 
for (auto pair : responses) { 
if (lowerInput.find(pair.first) 
!= string::npos) { 
return pair.second; 
} 
} 
return "Sorry, I don't understand that question."; 
20 
} 
// Start Chat 
void startChat() { 
string userInput; 
cout << "\nEnter your name : "; 
getline(cin, username); 
cout << "\n=====================================\n"; 
cout << "    
  SMART COLLEGE CHATBOT\n"; 
cout << "=====================================\n"; 
typingAnimation( 
"Hello " + username + 
"! Type 'bye' to exit." 
); 
while (true) { 
cout << "\nYou : "; 
getline(cin, userInput); 
string lowerInput = 
21 
22 
 
                toLower(userInput); 
 
            // Exit 
            if (lowerInput == "bye") { 
 
                typingAnimation( 
                    "Goodbye! Have a nice day." 
                ); 
 
                break; 
            } 
 
            string response = 
                getResponse(userInput); 
 
            typingAnimation(response); 
 
            saveHistory(userInput, 
                        response); 
        } 
    } 
}; 
 
// Admin Panel 
class Admin { 
 
public: 
void adminLogin() { 
string password; 
cout << "\nEnter Admin Password : "; 
cin >> password; 
// Password 
if (password != "admin123") { 
cout << "Wrong Password!\n"; 
return; 
} 
int choice; 
while (true) { 
cout << "\n========== ADMIN PANEL ==========\n"; 
cout << "1. Add Response\n"; 
cout << "2. View Chat History\n"; 
cout << "3. Exit Admin Panel\n"; 
23 
24 
 
            cout << "Enter choice : "; 
 
            cin >> choice; 
 
            switch (choice) { 
 
            case 1: 
                addResponse(); 
                break; 
 
            case 2: 
                viewHistory(); 
                break; 
 
            case 3: 
                return; 
 
            default: 
                cout << "Invalid Choice!\n"; 
            } 
        } 
    } 
 
    // Add new responses 
    void addResponse() { 
 
        string question, 
answer; 
cin.ignore(); 
cout << "\nEnter keyword/question : "; 
getline(cin, question); 
cout << "Enter response : "; 
getline(cin, answer); 
ofstream file("data.txt", 
ios::app); 
file << question 
<< "|" 
<< answer 
<< endl; 
file.close(); 
cout << "\nResponse Added Successfully!\n"; 
} 
// View history 
void viewHistory() { 
25 
ifstream history("history.txt"); 
string line; 
cout << "\n========== CHAT HISTORY ==========\n"; 
while (getline(history, line)) { 
cout << line << endl; 
} 
history.close(); 
} 
}; 
// Main Function 
int main() { 
srand(time(0)); 
ChatBot bot; 
Admin admin; 
bot.setColor(); 
26 
bot.loadResponses(); 
int choice; 
while (true) { 
cout << "\n=====================================\n"; 
cout << "    
  COLLEGE CHATBOT SYSTEM\n"; 
cout << "=====================================\n"; 
cout << "1. Start Chat\n"; 
cout << "2. Admin Panel\n"; 
cout << "3. Exit\n"; 
cout << "\nEnter your choice : "; 
cin >> choice; 
cin.ignore(); 
switch (choice) { 
case 1: 
bot.startChat(); 
break; 
27 
case 2: 
admin.adminLogin(); 
break; 
case 3: 
cout << "\nExiting Program...\n"; 
return 0; 
default: 
cout << "Invalid Choice!\n"; 
} 
} 
return 0; 
}