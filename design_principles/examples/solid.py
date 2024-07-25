# Single Responsibility Principle (SRP)

# WRONG: Class has two responsibilities, fetching and writing, SRP states
# that each class should only have a single responsibility.

class FetchSiteWriteToFile():
    def fetch_site(self):
        print("fetch site")

    def write_to_file(self):
        print("write to file")

# CORRECT: Each class has its own responsiblity and the code is not tightly
# coupled.
class FetchSite():
    def fetch_site(self):
        print("fetch site")

class WriteFile():
    def write_to_file(self):
        print("write to file")

#--------------------------------------------------------------------------

# Liskov Substitution Principle (LSP)
class Animal():
    def make_noise(self):
        print("i'm making noise!")

# WRONG: LSP states that objects of a superclass should be replaceable with
# objects of its subclasses without breaking the code. This is used to
# ensure that subclasses objects extends the base class without changing
# its behaviour.
class DumbDog(Animal):
    def make_noise(self):
        raise Exception("I can't make noise")

# CORRECT: Each of the following classes extends the base class without
# changing its behaviour.
class Dog(Animal):
    def make_noise(self):
        print("bow wow")

class Cat(Animal):
    def make_noise(self):
        print("meow meow")

#--------------------------------------------------------------------------
from abc import ABC, abstractmethod

# Interface Segregation Principle (ISP)

# WRONG: ISP states that you should keep your interfaces small. Interfaces
# should be client specific, clients should not be forced to implement
# methods that they aren't going to use.
# A TapEvents class impleenting this interface whould have to implement
# the on_long_click() method, which will probably not be used.
class ClickInterface(ABC):
    @abstractmethod
    def on_click(self):
        ...

    @abstractmethod
    def on_long_click(self):
        ...

# CORRECT: Each interface is client specific, and each client can implement
# one of the interfaces as needed, without being forced to implement 
# unwanted methods.
class OnClickInterface(ABC):
    @abstractmethod
    def on_click(self):
        ...

class OnLongClickInterface(ABC):
    @abstractmethod
    def on_long_click(self):
        ...

#--------------------------------------------------------------------------
# Open/Closed Principle (OCP)

class XBoxController:
    def jump_on_a(self):
        ...

    def hit_on_x(self):
        ...

class PlaystationController:
    def jump_on_x(self):
        ...

    def hit_on_square(self):
        ...

# WRONG: OCP states that a class should be open for extension and closed 
# for modifications. Game is not OCP compliant as if you want to use the
# PlaystationController class you would have to modify your previous code.
class Game:
    def __init__(self, controller: XBoxController):
        self._controller = controller

class Controller(ABC):
    @abstractmethod
    def jump(self):
        ...

    def hit(self):
        ...

class XBoxControllerOCP(Controller):
    def jump(self):
        ...

    def hit(self):
        ...

class PlaystationControllerOCP(Controller):
    def jump(self):
        ...

    def hit(self):
        ...

# CORRECT: GameOCP is OCP compliant as it requires the controller to
# implement the Controller interface, thus you can add as many controllers
# you linke, and you won't have to modify the existing code to do so.
class GameOCP:
    def __init__(self, controller: Controller):
        self._controller = controller

#--------------------------------------------------------------------------
# Dependency Inversion Principle (DIP)

class Book(ABC):
    @abstractmethod
    def read_all(self):
        ...

class DaVinciCode(Book):
    def read_all(self):
        return

# WRONG: DIP states that an abstration shouldn't depend on detail, this
# means that the usage detail of a component should not impact another
# component in a way that the interface hasn't determined, simillarly to
# LSP.
class AnoyingOrange(Book):
    def read_all(self):
        raise Exception("fininshed")

# WRONG: DIP states that high-level and lower-level classes shouldn't 
# depend on each other but over the same abstraction, simillarly to OCP.
class Reader:
    def __init__(self, book: DaVinciCode):
        self.current_book = book

# CORRECT: AnoyinOrangeRemastered does not impact its usage in 
# higher-level classes in not specified ways in the interface.
class AnoyinOrangeRemastered(Book):
    def read_all(self):
        return

# CORRECT: GenericReader depends on the same abstraction as the lower
# level classes.
class GenericReader:
    def __init__(self, book: Book):
        self.current_book= book
