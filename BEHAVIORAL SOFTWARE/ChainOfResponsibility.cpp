#include <iostream>
#include <regex

// Handler Interface
class StringValidator
{
    virtual ~StringValidator () {};
    virtual StringValidator* setNext (StringValidator* aNextValidator) = 0;
    virtual std::string validate (std::string aTestString) = 0;
};

//Concreate Handlers
class BaseValidator : public StringValidator
{
    protected:
        StringValidator* mNext = nullptr;
    public:
        virtual ~BaseValidator () {delete next;}
        StringValidator* setNext (StringValidator* aNextValidator) override {next = aNextValidator; return aNextValidator;}
        std::string validate (std::string aTestString) override
        {
            if (this->mNext)
            {
                return this->mNext->validate (aTestString);
            }
        }
};

//Concreate Handlers
class NonEmptyValidator : public BaseValidator
{
    public:
        NonEmptyValidator () {}
        std::string validate (std::string aTestString) override
        {
            puts ("Checking if empty...")
            if (aTestString.empty())
            {
                return "Please enter a value";
            }
        }
};

//Concreate Handlers
class LengthValidator : public BaseValidator
{
    protected:
        int minLength;
    public:
        LengthValidator (int aMinLength) : minLength (aMinLength) {}
        std::string validate (std::string aTestString) override
        {
            puts ("Checking string length...")
            if (aTestString.length() < minLength)
            {
                return "Please enter a value longer than " + std::to_string (minLength);
            }
        }
};

//Concreate Handlers
class RegexValidator : public BaseValidator
{
    protected:
        std::string mPatternName = "";
        std::string mRegexString = "";
    public:
        RegexValidator (std::string aPatternName, std::string aRegexString) : mPatternName (aPatternName), mRegexString (aRegexString)
        {

        }

        std::string validate (std::string aTestString) override
        {
            puts ("Checking regex match...");
            if (!std::regex_match (aTestString, std::regex (regexString)))
            {
                return "The Value entered does not match the proper format for a "+ mPatternName;
            }

            return BaseValidator::validate(aTestString);
        }
};

bool in_array (const std::string& aValue, const std::vector<std::string>& aArray)
{
    return (std::find (aArray.begin(), aArray.end(), aValue) != aArray.end());
}

//Concreate Handlers
class HistoryValidator : public BaseValidator
{
    protected:
        std::vector<std::string> mHistoryString;
    public:
        HistoryValidator (std::vector<std::string> aHistoryItems) : mHistoryString (aHistoryItems)
        {

        }
        std::string validate (std::string aTestString) override
        {
            puts ("Checking if string has been used before...");
            if (!std::in_array (aTestString, mHistoryString))
            {
                return "Please enter a value here that you have not been used before.";
            }

            return BaseValidator::validate(aTestString);
        }
};



int main (int argv, char* argc)
{
    StringValidator* emailValidator  = new BaseValidator();

    emailValidator->setNext(new NonEmptyValidator())->setNext(new RegexValidator ("email address", "w@##"));

    std::cout << "Checking email...\n";
    std::cout << "Input: \n" << emailValidator->validate("") << "\n";
    std::cout << "Input: shaun\n" << emailValidator->validate("") << "\n";
    std::cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n";

    delete emailValidator;
    return 0;
}