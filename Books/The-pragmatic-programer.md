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

**Tip 26**: "select" Isn't Broken
	- It is much more likely that the bug exists in the application code under development. It is generally more profitable to assume that the application code is incorrectly calling into a library than to assume that the library itself is broken. 
