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

    
