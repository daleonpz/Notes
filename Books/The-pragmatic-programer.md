---
title: The pragmatic programmer
author: Androw Hund / David Thomas
---

# Ch01: Preface
- **Tip 01**: Care About your craft: do it well
    - It's a continuous process: continuously small improvements
- **Tip 02**: Think! about your work: never run on auto-pilot. Think on what you are doing
    - Take responsibility: When you do accept the responsibility for an outcome, you should expect to be held accountable for it. When you make a mistake (as we all do) or an error in judgment, admit it honestly and try to offer options.  Don't blame someone or something else, or make up an excuse. Don't blame all the problems on a vendor, a programming language, management, or your coworkers. Any and all of these may play a role, but it is up to you to provide solutions, not excuses. 
- **Tip 03**: Provide Options, don't make lame excuses
    - Software entropy:
        - Entropy hits software hard
        - When disorder increases in software, programmers call it "software rot."
        - The most important factor for software rot is psychology or culture at work on a project

- **Tip 04**: Don't live with broken windows
    - The **broken window theory** One broken window, left unrepaired for any substantial length of time, instills in the inhabitants of the building a sense of abandonment—a sense that the powers that be don't care about the building. So another window gets broken. People start littering. Graffiti appears. Serious structural damage begins. In a relatively short space of time, the building becomes damaged beyond the owner's desire to fix it, and the sense of abandonment becomes reality. 
    - Don't leave "broken windows" (bad designs, wrong decisions, or poor code) unrepaired. Fix each one as soon as it is discovered. If there is insufficient time to fix it perhaps you can comment out the offending code.

- **Tip 05**: Be a catalyst of change
    - Putting out Fires:
        - If you find yourself working on a project with quite a few broken windows, it's all too easy to slip into the mindset of "All the rest of this code is crap, I'll just follow suit." It doesn't matter if the project has been fine up to this point. 
        - By the same token, if you find yourself on a team and a project where the code is pristinely beautiful—cleanly written, well designed, and elegant—you will likely take extra special care not to mess it up. Even if there's a fire raging (deadline, release date, trade show demo, etc.), you don't want to be the first one to make a mess. 
    - Stone Soup and boiled frogs:
        - You may be in a situation where you know exactly what needs doing and 
how to do it. The entire system just appears before your eyes—you know it's 
right. But the  "start-up fatigue" will be there. So try to ask for something reasonable to develop and do it well, and say things such as "I would be great if we add ...".

- **Tip 06**: Remember the big picture
    - Keep an eye on the big picture. Constantly review what's happening around you, not just what you personally are doing. 
    - Good-enough software: it's impossible to create bug-free code, but do a good-enough code for your users, future maintainers and your our peace.

- **Tip 07**: Make quality a requirements issue
    - Know when to stop: artists will tell you that all the hard work is ruined if you don't know when to stop. If you add layer upon layer, detail over detail, the painting becomes lost in the paint. 
    - Sometimes it's better to ship good code sooner than perfect code in the future. Users can give you feedback and make your code better in the future.

- **Tip 08**: Invest regularly in your knowledge portfolio
    - Your knowledge portfolio:
        - Serious investors invest regularly—as a habit. 
        - Diversification is the key to long-term success. 
        - Smart investors balance their portfolios between conservative and high-risk, high-reward investments. 
        - Investors try to buy low and sell high for maximum return. 
        - Portfolios should be reviewed and rebalanced periodically. 
    - Goals:
        - Learn a new language every year: new perspectives
        - Read a technical book each quarter: new technologies
        - Read non-technical books also: understand people
        - Meet people outside your "company"
        - Stay current
        - Try to use what you have learned in your new project

- **Tip 09**: Critically analyze what you read and hear
    - Critical thinking: you must ensure that your knowledge is accurate and not influenced by external factors.

- **Tip 10**: It's both what you say and the way you say it
    - Communicate:
        - Know what you want to say: iterate until your ideas are clear and understandable
        - Know your audience: (WISDOM acrostic)
            - What they Want?
            - What is their Interest?
            - How Sophisticated are they?
            - How much Detail they want?
            - Who do you want to Own the information?
            - How can you Motivate them to listen?
        - Choose your moment: the right move at the wrong time is a bad move
        - Choose your style: not all the people like the same flavor
        - Make it look good or sexy
        - Involve your audience: create relationships
        - Be a listener
        - Get back to people: make them to people, they gave you a part of your time

# Ch02: A pragmatic approach
- **Tip 11**: DRY - Don't Repeat Yourself
    - The evils of duplication:
        - The knowledge and the environment changes day by day. Programmers are constantly maintaining the code. 
        - Imposed duplication: the environment seems to require duplication
            - Try to use templates
            - Code and comments shouldn't deliver the same information
            - Documentation and code are representations of the same knowledge, if one changes the other should change automatically
        - Inadvertent duplication: don't realize that you are duplicating information
            - Bad design, classes that duplicates information. Set as attribute data that depends on other attributes, instead of using a method
            - Balance between performance and information duplication
        - Impatient duplication: duplicate seems easier
            - Shortcuts make for long delays
        - Interdeveloper duplication: multiple people duplicate a piece of information 
            - Active and frequent communication between developers

- **Tip 12**: Make it easy to reuse
    - If it is not easy, people won't do it
- **Tip 13**: Elimitate effects between unrelated things
    - Orthogonally: "two lines are independent" . decoupling.
    - Orthogonally promotes reuse
    - More stable system
    - If one module fails doesn't affect others
    - Modularity
    - Design in layers like OSI model
    - Coding: keep your code decoupled, avoid global data, avoid similar functions
    - Easier to test
- **Tip 14**: There are no final decisions
    - Reversibitily: Nothing is more dangerous than an idea, if it's the only one 
    - Technology changes overtime
    - World is always changing
    - Flexible architecture
- **Tip 15**: Use tracer bullets to find the target
    - If the tracer bullet hits the target, then so are the regular bullets
    - Tracer development is consistent with the idea that a project is never finished: there will always be changes required and functions to add. It is an incremental approach.
    - Model based approach. Traceability
    - The distinction is important enough to warrant repeating. Prototyping generates disposable code. Tracer code is lean but complete, and forms part of the skeleton of the final system
    - Benefits:
    	- Users get to see something working early
	- Developers build a structure to work in
	- You have an integration platform.
	- You have something to demonstrate.
	- You have a better feel for progress.
- **Tip 16**: Prototype to learn	
     - You can prototype anything that carries risk. Anything that hasn't been tried before, or that is absolutely critical to the final system. Anything unproven, experimental, or doubtful. Anything you aren't comfortable with. 
     - you can ignore Robustnesn, completeness, correctness and style
     -  You must make it very clear that this code is disposable, incomplete, and unable to be completed.
     
- **Tip 17** Program Close to the Problem domain
	- If you are writing in the problem domain, you can also perform domain-specific validation, reporting problems in terms your users can understand.

**Tip 18**: Estimate to Avoid Surprises
	- By learning to estimate, and by developing this skill to the point where you have an intuitive feel for the magnitudes of things, you will be able to show an apparent magical ability to determine their feasibility
	- One of the interesting things about estimating is that the units you use make a difference in the interpretation of the result.
	- Duration: 1-15 days -> days
	- Duration: 3-8 weeks -> weeks
	- Duration: 8-30 weeks -> months
	- Duration: 30+ -> think hard before giving an estimation
	- So, if after doing all the necessary work, you decide that a project will take 125 working days (25 weeks), you might want to deliver an estimate of "about six months."
	- Basic estimating trick that always gives good answers: ask someone who's already done it. 
	- We think it's a great idea to record your estimates so you can see how close you were.
	- What to Say When Asked for an Estimate: You say "I'll get back to you."	

# Ch03: The basic tools
- Tools amplify your talent. The better your tools, and the better you know how to use them, the more productive you can be.
- **Tip 20**: Keep Knowledge in Plain Text
	- We believe that the best format for storing knowledge persistently is plain text.
	- benefits? 
		- Insurance against obsolescence: Human-readable forms of data, and self-describing data, will outlive all other forms of data and the applications that created them.  
		- Leverage: Virtually every tool in the computing universe, from source code management systems to compiler environments to editors and stand-alone filters, can operate on plain text 
		- Easier testing: If you use plain text to create synthetic data to drive system tests, then it is a simple matter to add, update, or modify the test data without having to create any special tools to do so

- **Tip 21**: Use the Power of Command Shells
	- A benefit of GUIs is WYSIWYG—what you see is what you get. The disadvantage is WYSIAYG—what you see is all you get.
- **Tip 22**: Use a Single Editor Well
	- Choose an editor, know it thoroughly, and use it for all editing tasks. If you use a single editor (or set of keybindings) across all text editing activities, you don't have to stop and think to accomplish text manipulation: the necessary keystrokes will be a reflex. The editor will be an extension of your hand; the keys will sing as they slice their way through text and thought.   

- **Tip 23**: Always Use Source Code Control
- **Tip 24**: Fix the Problem, Not the Blame
	- Unfortunately, modern computer systems are still limited to doing what you tell them to do, not necessarily what you want them to do.
	- Once you think you know what is going on, it's time to find out what the program thinks is going on.
	- Rubber duck debugging

- **Tip 26**: "select" Isn't Broken
	- It is much more likely that the bug exists in the application code under development. It is generally more profitable to assume that the application code is incorrectly calling into a library than to assume that the library itself is broken. 

- **Tip 27**: Don't Assume It—Prove It
	-  Don't gloss over a routine or piece of code involved in the bug because you "know" it works. Prove it. Prove it in this context, with this data, with these boundary conditions. 
	- Debugging Checklist 
		- Is the problem being reported a direct result of the underlying bug, or merely a symptom? 
		- Is the bug really in the compiler? Is it in the OS? Or is it in your code? 
		- If you explained this problem in detail to a coworker, what would you say? 
		- If the suspect code passes its unit tests, are the tests complete enough? What happens if you run the unit test with this data? 
		- Do the conditions that caused this bug exist anywhere else in the system?

- **Tip 28**: Learn a Text Manipulation Language
	- These languages are important enabling technologies. Using them, you can quickly hack up utilities and prototype ideas—jobs that might take five or ten times as long using conventional languages.
	
- **Tip 29**: Write Code That Writes Code
	- There are two main types of code generators:
		- Passive code generators are run once to produce a result.Passive code generators save typing. They are basically parameterized templates, generating a given output from a set of inputs. Once the result is produced, it becomes a full-fledged source file in the project; it will be edited, compiled, and placed under source control just like any other file. Its origins will be forgotten.
		- Active code generators are used each time their results are required.  Often, active code generators read some form of script or control file to produce their results.

# Ch04: Pragmatic Paranoia
- **Tip 30**: You Can't Write Perfect Software
- **Tip 31**: Design with Contracts
	- It is a simple yet powerful technique that focuses on documenting (and agreeing to) the rights and responsibilities of software modules to ensure program correctness.
	- **Preconditions**. What must be true in order for the routine to be called; the routine's requirements. A routine should never get called when its preconditions would be violated. It is the caller's responsibility to pass good data 
	- **Postconditions** What the routine is guaranteed to do; the state of the world when the routine is done. The fact that the routine has a postcondition implies that it will conclude: infinite loops aren't allowed. 
	- **Class invariants**  A class ensures that this condition is always true from the perspective of a caller. During internal processing of a routine, the invariant may not hold, but by the time the routine exits and control returns to the caller, the invariant must be true. 
	- If all the routine's preconditions are met by the caller, the routine shall guarantee that all postconditions and invariants will be true when it completes.
	- Simply enumerating at design time what the input domain range is, what the boundary conditions are, and what the routine promises to deliver—or, more importantly, what it doesn't promise to deliver—is a huge leap forward in writing better

- **Tip 32**: Crash Early
	- Dead Programs Tell No Lies
	- each and every case/switch statement needs to have a default clause—we want to know when the "impossible" has happened).
	- If you don't have an exception mechanism, or if your libraries don't throw exceptions, then make sure you handle the errors yourself

- **Tip 33**: If It Can't Happen, Use Assertions to Ensure That It Won't
	- Assertive Programming
	- Whenever you find yourself thinking "but of course that could never happen," add code to check it. 
	- never put code that must be executed into an assert.
	- If a pointer passed in to your procedure should never be NULL, then check for it: 

```c
 void writeString(char *string) { 
 	assert(string != NULL); 
 	... 
```
-  
	- Don't use assertions in place of real error handling.
	- Leave Assertions Turned On
		- testing cannot find all the bugs.
		- programs run in a dangerous world.
	- Your first line of defense is checking for any possible error, and your second is using assertions to try to detect those you've missed.
	- Even if you do have performance issues, turn off only those assertions that really hit you.

- **Tip 34**: Use Exceptions for Exceptional Problems
	- One of the problems with exceptions is knowing when to use them
	- Assume that an uncaught exception will terminate your program and ask yourself, "Will this code still run if I remove all the exception handlers?" If the answer is "no," then maybe exceptions are being used in nonexceptional circumstances.
	- An error handler is a routine that is called when an error is detected. 
	- Error Handlers Are an Alternative to exceptions

- **Tip 35**: Finish What You Start
	- Most of the time, resource usage follows a predictable pattern: you allocate the resource, use it, and then deallocate it.  However, many developers have no consistent plan for dealing with resource allocation and deallocation. 
	- Deallocate resources in the opposite order to that in which you allocate them. That way you won't orphan resources if one resource contains references to another. 
	- When allocating the same set of resources in different places in your code, always allocate them in the same order. This will reduce the possibility of deadlock. 

# Ch05: Bend or Break
-  we suggested that writing "shy" code is beneficial. But "shy" works two ways: don't reveal yourself to others, and don't interact with too many people.
- **Tip 36**: Minimize Coupling Between Modules 
	- Traversing relationships between objects directly can quickly lead to a combinatorial explosion of dependency relationships. You can see symptoms of this phenomenon in a number of ways:
		- Large C or C++ projects where the command to link a unit test is longer than the test program itself 
		- "Simple" changes to one module that propagate through unrelated modules in the system 
		- Developers who are afraid to change code because they aren't sure what might be affected
	- The Law of Demeter for Functions **ADD IMAGE HERE**

- **Tip 37**: Configure, Don't Integrate
	- we want to make our systems highly configurable.
	- Use metadata to describe configuration options for an application: tuning parameters, user preferences, the installation directory, and so on.
	- We use the term in its broadest sense. Metadata is any data that describes the application—how it should run, what resources it should use, and so on.  Typically, metadata is accessed and used at runtime, not at compile time.  You use metadata all the time—at least your programs do

- **Tip 38**: Put Abstractions in Code Details in Metadata
	- Our goal is to think declaratively (specifying what is to be done, not how) and create highly dynamic and adaptable programs. We do this by adopting a general rule: program for the general case, and put the specifics somewhere else—outside the compiled code base.
	- Benefits:
		- It forces you to decouple your design, which results in a more flexible and adaptable program. 
		- It forces you to create a more robust, abstract design by deferring details—deferring them all the way out of the program. 
		- You can customize the application without recompiling it. You can also use this level of customization to provide easy work-arounds for critical bugs in live production systems.
		- Metadata can be expressed in a manner that's much closer to the problem domain than a general-purpose programming language might be 
		- You may even be able to implement several different projects using the same application engine, but with different metadata

- **Tip 39**: Analyze Workflow to Improve Concurrency 
	- There are two aspects of time that are important to us: concurrency (things happening at the same time) and ordering (the relative positions of things in time).
	- We need to allow for concurrency[3] and to think about decoupling any time or order dependencies.

- **Tip 40**: Design Using Services
	- Instead of components, we have really created services—independent, concurrent objects behind well-defined, consistent interfaces.

- **Tip 41**: Always Design for Concurrency
	- With linear code, it's easy to make assumptions that lead to sloppy programming. But concurrency forces you to think through things a bit more carefully—you're not alone at the party anymore. Because things can now happen at the "same time," you may suddenly see some time-based dependencies.
	- Going the other way (trying to add concurrency to a nonconcurrent application) is much harder. If we design to allow for concurrency, we can more easily meet scalability or performance requirements when the time comes—and if the time never comes, we still have the benefit of a cleaner design.

- **Tip 42**: Separate Views from Models
	- Obviously, we don't want to have three separate copies of the data. So we create a **model** —the data itself, with common operations to manipulate it.  Then we can create separate **views** that display the data in different ways: as a spreadsheet, as a graph, or in a totals box. Each of these views may have its own **controller**. The graph view may have a controller that allows you to zoom in or out, or pan around the data, for example. None of this affects the data itself, just that view.
	- **Model**. The abstract data model representing the target object.  The model has no direct knowledge of any views or controllers. 
	- **View**. A way to interpret the model. It subscribes to changes in the model and logical events from the controller. 
	- **Controller**. A way to control the view and provide the model with new data. It publishes events to both the model and the view.

- **Tip 43**: Use Blackboards to Coordinate Workflow

# Ch06: While you are Coding
- **Tip 44**: Don't Program by Coincidence
	- Fred doesn't know why the code is failing because he didn't know why it worked in the first place. It seemed to work, given the limited "testing" that Fred did, but that was just a coincidence. Buoyed by false confidence, Fred charged ahead into oblivion
	- Always be aware of what you are doing. Fred let things get slowly out of hand, until he ended up boiled
	- Don't code blindfolded. Attempting to build an application you don't fully understand, or to use a technology you aren't familiar with, is an invitation to be misled by coincidences. 
	- Proceed from a plan, whether that plan is in your head, on the back of a cocktail napkin, or on a wall-sized printout from a CASE tool. 
	- Rely only on reliable things. Don't depend on accidents or assumptions. If you can't tell the difference in particular circumstances, assume the worst. 
	-  Document your assumptions. Design by Contract, can help clarify your assumptions in your own mind, as well as help communicate them to others. 
	- Don't just test your code, but test your assumptions as well.  Don't guess; actually try it. Write an assertion to test your assumptions (see Assertive Programming). If your assertion is right, you have improved the documentation in your code. If you discover your assumption is wrong, then count yourself lucky. 
	- Prioritize your effort. Spend time on the important aspects; more than likely, these are the hard parts. If you don't have fundamentals or infrastructure correct, brilliant bells and whistles will be irrelevant. 
	- Don't be a slave to history. Don't let existing code dictate future code. All code can be replaced if it is no longer appropriate. Even within one program, don't let what you've already done constrain what you do next—be ready to refactor. This decision may impact the project schedule. The assumption is that the impact will be less than the cost of not making the change.

- **Tip 45**: Estimate the Order of Your Algorithms
	- If you're not sure how long your code will take, or how much memory it will use, try running it, varying the input record count or whatever is likely to impact the runtime. Then plot the results. You should soon get a good idea of the shape of the curve. Is it curving upward, a straight line, or flattening off as the input size increases? Three or four points should give you an idea. 
	- Also consider just what you're doing in the code itself. A simple O(n2) loop may well perform better that a complex, O(n lg(n)) one for smaller values of n, particularly if the O(n lg(n)) algorithm has an expensive inner loop.

- **Tip 46**: Test Your Estimates
	- If it's tricky getting accurate timings, use code profilers to count the number of times the different steps in your algorithm get executed, and plot these figures against the size of the input.	
	- You also need to be pragmatic about choosing appropriate algorithms—the fastest one is not always the best for the job

- **Tip 47**: Refactor Early, Refactor Often
	- Rewriting, reworking, and re-architecting code is collectively known as refactoring.
	-  Any number of things may cause code to qualify for refactoring: 
		- Duplication. You've discovered a violation of the DRY principle (The Evils of Duplication). 
		- Nonorthogonal design. You've discovered some code or design that could be made more orthogonal (Orthogonality). 
		- Outdated knowledge. Things change, requirements drift, and your knowledge of the problem increases. Code needs to keep up. 
		- Performance. You need to move functionality from one area of the system to another to improve performance.
	- Martin Fowler offers the following simple tips on how to refactor without doing more harm than good:
		- Don't try to refactor and add functionality at the same time. 
		- Make sure you have good tests before you begin refactoring. Run the tests as often as possible. That way you will know quickly if your changes have broken anything.
		- Take short, deliberate steps: move a field from one class to another, fuse two similar methods into a superclass. Refactoring often involves making many localized changes that result in a larger-scale change. If you keep your steps small, and test after each step, you will avoid prolonged debugging.

- **Tip 48**: Design to Test
	- We like to think of unit testing as testing against contract (see Design by Contract). We want to write test cases that ensure that a given unit honors its contract. This will tell us two things: whether the code meet the contract, and whether the contract means what we think it means. We want to test that the module delivers the functionality it promises, over a wide range of test cases and boundary conditions.
	- By making the test code readily accessible, you are providing developers who may use your code with two invaluable resources: 
		- Examples of how to use all the functionality of your module 
		- A means to build regression tests to validate any future changes to the code
	- All software you write will be tested—if not by you and your team, then by the eventual users—so you might as well plan on testing it thoroughly. A little forethought can go a long way toward minimizing maintenance costs and help-desk calls.
	- Perl makes it easier to collate and analyze test results to ensure compliance, but the big advantage is simply that it's a standard—tests go in a particular place, and have a certain expected output.

- **Tip 49**: Test Your Software, or Your Users Will
- **Tip 50**: Don't Use Wizard Code You Don't Understand
	- We are not against wizards. On the contrary, we dedicate an entire section (Code Generators) to writing your own. But if you do use a wizard, and you don't understand all the code that it produces, you won't be in control of your own application. You won't be able to maintain it, and you'll be struggling when it conies time to debug. 

# Ch07: Before the project
- **Tip 51**: Don't Gather Requirements—Dig for Them 
- **Tip 52**: Work with a User to Think Like a User
- **Tip 53**: Abstractions Live Longer than Details
- **Tip 54**: Use a Project Glossary
	- It's very hard to succeed on a project where the users and developers refer to the same thing by different names or, even worse, refer to different things by the same name.
- **Tip 55**: Don't Think Outside the Box—Find the Box
	- The secret to solving the puzzle is to identify the real (not imagined) constraints, and find a solution therein
	-  If the "box" is the boundary of constraints and conditions, then the trick is to find the box, which may be considerably larger than you think.  The key to solving puzzles is both to recognize the constraints placed on you and to recognize the degrees of freedom you do have, for in those you'll find your solution. 
	- When faced with an intractable problem, enumerate all the possible avenues you have before you. Don't dismiss anything, no matter how unusable or stupid it sounds. Now go through the list and explain why a certain path cannot be taken. Are you sure? Can you prove it?
	- There must be an easier way: That's when you step back a pace and ask yourself these questions: 
		- Is there an easier way? 
		- Are you trying to solve the right problem, or have you been distracted by a peripheral technicality? 
		- Why is this thing a problem? 
		- What is it that's making it so hard to solve? 
		- Does it have to be done this way? 
		- Does it have to be done at all? 

- **Tip 56**: Listen to Nagging Doubts—Start When You're Ready
	- Great performers share a trait: they know when to start and when to wait.  The diver stands on the high-board, waiting for the perfect moment to jump.  The conductor stands before the orchestra, arms raised, until she senses that the moment is right to start the piece.

- **Tip 57**: Some Things Are Better Done than Described
	- Writing a specification is quite a responsibility.  The problem is that many designers find it difficult to stop. They feel that unless every little detail is pinned down in excruciating detail they haven't earned their daily dollar. At some point you should start coding
	- You'll find that a healthy development process encourages feedback from implementation and testing into the specification process.

- **Tip 58**: Don't Be a Slave to Formal Methods
	- always remember that formal development methods are just one more tool in the toolbox. If, after careful analysis, you feel you need to use a formal method, then embrace it

# Ch08: Pragmatic projects
- **No broken windows**: Teams as a whole should not tolerate broken windows—those small imperfections that no one fixes. The team must take responsibility for the quality of the product, supporting developers who understand the no broken windows philosophy we describe in Software Entropy, and encouraging those who haven't yet discovered it.
- **Boiled Frogs**: Remember the poor frog in the pan of water, back in Stone Soup and Boiled Frogs? It doesn't notice the gradual change in its environment, and ends up cooked. Fight this. Make sure everyone actively monitors the environment for changes. Maybe appoint a chief water tester. Have this person check constantly for increased scope, decreased time scales, additional features, new environments—anything that wasn't in the original agreement
- **Communicate**: There is a simple marketing trick that helps teams communicate as one: generate a brand. When you start a project, come up with a name for it, ideally something off-the-wall. (In the past, we've named projects after things such as killer parrots that prey on sheep, optical illusions, and mythical cities.) Spend 30 minutes coming up with a zany logo, and use it on your memos and reports. Use your team's name liberally when talking with people. It sounds silly, but it gives your team an identity to build on, and the world something memorable to associate with your work
- **Tip 60**: Organize Around Functionality, Not Job Functions
	- We favor splitting teams functionally. Divide your people into small teams, each responsible for a particular functional aspect of the final system
	- The project needs at least two "heads"—one technical, the other administrative.
		- The technical head sets the development philosophy and style, assigns responsibilities to teams, and arbitrates the inevitable "discussions" between people. The technical head also looks constantly at the big picture.
		- The administrative head, or project manager, schedules the resources that the teams need, monitors and reports on progress, and helps decide priorities in terms of business needs

- **Tip 61**: Don't Use Manual Procedures
	- A great way to ensure both consistency and accuracy is to automate everything the team does
	- Let the computer do the repetitious, the mundane—it will do a better job of it than we would. We've got more important and more difficult things to do.

- **Tip 62**: Test Early. Test Often. Test Automatically.
	- Just because you have finished hacking out a piece of code doesn't mean you can go tell your boss or your client that it's done. It's not. First of all, code is never really done. More importantly, you can't claim that it is usable by anyone until it passes all of the available tests.  We need to look at three main aspects of project-wide testing: what to test, how to test, and when to test.

- **Tip 68**: Build Documentation In, Don't Bolt It On
	- In general, comments should discuss why something is done, its purpose and its goal. The code already shows how it is done, so commenting on this is redundant—and is a violation of the DRY principle.
	-  Remember that you (and others after you) will be reading the code many hundreds of times, but only writing it a few times. Take the time to spell out `connectionPool` instead of `cp`.

- **Tip 64**: Use Saboteurs to Test Your Testing 
	-  If you are really serious about testing, you might want to appoint a project saboteur. The saboteur's role is to take a separate copy of the source tree, introduce bugs on purpose, and verify that the tests will catch them.  When writing tests, make sure that alarms sound when they should

- **Tip 66**: Find Bugs Once 
	-  Once a human tester finds a bug, it should be the last time a human tester finds that bug. The automated tests should be modified to check for that particular bug from then on, every time, with no exceptions, no matter how trivial, and no matter how much the developer complains and says, "Oh, that will never happen again."

- **Tip 69**: Gently Exceed Your Users' Expectations
	- If you work closely with your users, sharing their expectations and communicating what you're doing, then there will be few surprises when the project gets delivered.  This is a **BAD THING**. Try to surprise your users. Not scare them, mind you, but delight them.  Give them that little bit more than they were expecting. The extra bit of effort it requires to add some user-oriented feature to the system will pay for itself time and time again in goodwill.  Listen to your users as the project progresses for clues about what features would really delight them

- **Tip 70**: Sign Your Work
	- People should see your name on a piece of code and expect it to be solid, well written, tested, and documented. A really professional job.  Written by a real professional.  A Pragmatic Programmer.
	- While code must be owned, it doesn't have to be owned by an individual. In fact, Kent Beck's successful eXtreme Programming method recommends communal ownership of code (but this also requires additional practices, such as pair programming, to guard against the dangers of anonymity).
