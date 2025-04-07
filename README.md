### SOLID Principle for Opps

```
S-Single Responsibility Principle
O-Open/Close Principle
L-Liskov Substitution Principle
I-Interface Segmented Principle
D-Dependency Inversion Principle
```
### Advantage of SOLID Principle
```
1. Avoid Dupulicate code
2. Easy to Maintain
3. Easy to Understand
4. Flexible Software
5. Reduce Complexity
```

### Definition
```
S : A class or function should have only one reason to change.

O : Open for Extension but closed for Modification. Don't make change in already tested code. Extend the class for extra capability.

L : If class B is subclass of class A, then we should be able to replace object of A with B without breaking the behaviour of the program. 
    SubClass should extend the capability of parent class not narrow it down.

I : Interface should be such that client should not implement unnecessary function they do not need.

D : class should depends on interface rather than concreate class (Facade). Koi bhi member variable banao to wo interface type ka banao
```


