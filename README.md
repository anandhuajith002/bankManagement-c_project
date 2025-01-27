# Banking Management System

A comprehensive C-based banking management system that provides functionality for both customers and administrators to manage bank accounts and transactions.

## Features

### Customer Features
- Account Creation
  - Support for both Savings and Current accounts
  - Secure PIN setup
  - Email and phone number validation
- Account Management
  - View account details
  - Deposit funds
  - Withdraw funds
  - Change PIN
  - Transfer money to other accounts
- Security
  - PIN-based authentication
  - Validation checks for all inputs
  - Secure money transfer with recipient verification

### Admin Features
- Account Management
  - View all customer accounts
  - Search for specific accounts
  - Edit account details
  - Close accounts
- Security
  - Password-protected admin access
  - Separate admin authentication system

## Technical Details

### Data Structures
- Customer information stored in structures including:
  - Account number
  - Name
  - Email
  - Phone number
  - PIN
  - Account type (Savings/Current)
  - Balance

- Admin information stored in structures including:
  - Admin ID
  - Name
  - Phone number
  - Password

### File Management
- Customer data stored in CSV format
- Admin data stored in CSV format
- Automatic data persistence

### Input Validation
- Name validation (alphabets and spaces only)
- Phone number validation (10 digits)
- Email validation (proper format with @ and .com)
- PIN validation (8 digits)
- Duplicate check for phone numbers and email addresses

## Setup and Compilation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/banking-management-system.git
```

2. Navigate to the project directory:
```bash
cd banking-management-system
```

3. Compile the project:
```bash
gcc main.c admin.c bank.c createacc.c customer.c login.c -o bank
```

4. Run the application:
```bash
./bank
```

## Usage

### Main Menu
1. Login (Admin/Customer)
2. Create Account
3. Save Changes
4. Exit

### Admin Login
- Use admin ID and password from admin.csv
- Default admin credentials can be found in admin.csv

### Customer Login
- Use registered phone number and PIN
- New customers can create an account from the main menu

## File Structure
```
├── admin.c          # Admin functionality implementation
├── admin.h          # Admin header file
├── bank.c           # Core banking functions
├── bank.h           # Main header file with structure definitions
├── createacc.c      # Account creation functionality
├── createacc.h      # Account creation header file
├── customer.c       # Customer functionality implementation
├── customer.h       # Customer header file
├── login.c          # Login system implementation
├── login.h          # Login system header file
├── main.c          # Main program entry point
├── admin.csv       # Admin data storage
└── custo.csv       # Customer data storage
```

## Contributing
1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License
This project is open source and available under the [MIT License](LICENSE).

## Notes
- Make sure to regularly save changes using the "Save" option in the main menu
- Keep admin.csv and custo.csv files in the same directory as the executable
- Backup data files regularly to prevent data loss