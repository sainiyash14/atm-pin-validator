# Bank ATM PIN Validator

A simple, secure console-based C++ project that simulates ATM PIN authentication and banking transactions. Developed as a mini project for Computing Aptitude.

## Features

- **PIN Authentication:** 4-digit PIN validation with numeric and length checks
- **Attempt Limiting:** 3 attempts allowed, card is blocked after 3 failed tries
- **Menu-based Transactions:**
  - Check Balance
  - Withdraw Cash (with balance validation)
  - Deposit Cash
  - View Mini Statement
  - Safe Exit
- **User-Friendly Interface:** Clean, easy-to-read console output, no special characters

## How to Run

1. **Clone this repository:**
git clone https://github.com/sainiyash14/atm-pin-validator

2. cd atm-pin-validator


3. **Compile the program:**


4. **Test PIN:** Enter `1234` for successful authentication.

## Screenshots

See the `/screenshots` folder or the documentation PDF for sample outputs of:
- Welcome Screen
- PIN Entry
- Access Granted
- Transaction Menu
- Balance Inquiry
- Cash Withdrawal
- Deposit Transaction
- Mini Statement
- Access Denied (on failed authentication)

## Code Overview

- Uses **strings** for PIN processing
- **Loops** for repeated attempts and transactions
- **Conditional logic** for validations & menu handling

## Learning Outcomes

- Practical application of fundamental C++ concepts
- Input validation and error handling
- Menu-driven user interfaces
- Modular code structure

## Documentation

Find `Bank_ATM_PIN_Validator_PBL_Report.pdf` in the repo for full documentation, including:
- Project Aim & Objectives
- Technical Architecture
- Complete C++ Source Code
- Implementation Screenshots (place yours in marked spaces)
- Conclusion & Learning Outcomes

## Contributing

Fork this repo and submit pull requests to improve with:
- PIN change option
- Transaction history
- Multi-user support
- File/database integration
- Enhanced UI

## License

Open source for educational use.
