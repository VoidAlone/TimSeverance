# Module 6 - Hashing, Hash Tables, Equality, and Identity

## Big idea

Hashing is about using a key to quickly decide where data should live.

A hash table tries to turn lookup into a near-direct jump instead of a long search.

That is the dream:

- take a key
- run it through a hash function
- map the result to a bucket
- store or retrieve the value there

## Core vocabulary

- Hash table: a structure that stores key-value pairs using hashed keys
- Key: the thing used to decide where data belongs
- Value: the data associated with the key
- Bucket: a storage position in the underlying array
- Collision: two keys map to the same bucket
- Load factor: roughly `items / buckets`

## The basic mapping idea

Suppose the table has 10 buckets and the key is `42`.

A very simple hash idea is:

`42 % 10 = 2`

So bucket `2` becomes the target location.

That is the whole core concept: convert a key into a usable index.

Real hash functions can be much smarter than this, but the central story stays the same.

## Why collisions happen

Collisions are unavoidable in most practical hash tables.

If you have more possible keys than buckets, different keys will sometimes land in the same place.

So the real question is not "How do we avoid every collision forever?"

It is:

"How do we handle collisions well enough that operations stay fast most of the time?"

## Collision resolution strategies

### Chaining

Each bucket stores a secondary structure, often a linked list.

If multiple keys land in the same bucket, they are chained together there.

Good mental model: one apartment number, multiple people at that address.

### Open addressing

Instead of storing a secondary structure, we keep searching for another open bucket.

Common strategies:

- Linear probing
- Quadratic probing
- Double hashing

### Linear probing

If the target bucket is full, check the next one, then the next one, and so on.

This is simple, but it can create clustering where long runs of occupied buckets form.

### Quadratic probing

Still probes for another spot, but the jumps get larger according to a formula.

This helps reduce clustering compared to linear probing.

### Double hashing

Uses a second hash function to decide the jump pattern.

This tends to spread probes out more intelligently.

## Resizing

As the table fills up, collisions become more common.

So hash tables often resize when the load factor gets too high.

The usual process:

1. Create a larger underlying array
2. Re-hash every existing key into the new array
3. Replace the old table

This resize step is expensive when it happens, but it helps keep future operations efficient.

## Direct hashing

If keys are small integers in a manageable range, you can map each key directly to its own index.

This is very fast, but it can waste a huge amount of space if the possible key range is large.

Another classic tradeoff:

- more speed
- more space cost

## Equality vs identity

This part matters because hashing is not only about numbers. It is also about what it means for two keys to be "the same."

### Identity

Identity asks:

- Are these literally the same object?

In Python terms, `a is b` checks identity.

### Equality

Equality asks:

- Do these objects count as equal in value?

In Python terms, `a == b` checks equality.

These are not the same question.

### Example

If two distinct objects both represent the number string `"1"`, they may be equal in value while still being different objects in memory.

That distinction matters when choosing or designing keys.

## Hashability

For an object to work well as a hash key, its hash behavior must stay consistent while it is being used as a key.

This is why immutable objects are usually safer keys than mutable ones.

### Why mutability is dangerous

Imagine a list is used as a key idea based on its contents.

If the list changes later, then the "meaning" of that key has changed.

That can break lookups because the structure no longer matches the bucket logic that was used when it was stored.

Even when the language does not literally allow that exact key usage, the teaching lesson is still important:

- a key should have a stable identity or a stable value definition

## A practical way to think about keys

Whenever you use hashing, ask:

1. Are we identifying by object identity?
2. Or are we identifying by structural value?

Those lead to different expectations.

Example:

- If two student records have the same student ID, should they count as the same key?
- Or should two different objects always count as different, even if their fields match?

That is not just a programming detail. It is a design decision.

## Performance intuition

Hash tables are loved because they often give near-constant-time insert, search, and removal.

But that performance depends on:

- a decent hash function
- reasonable load factor
- good collision handling

When collisions pile up, performance can degrade.

## What to remember

- Hashing maps keys to storage locations
- Collisions are normal, so collision resolution matters
- Chaining and open addressing are the main strategies
- Resizing keeps the table from getting too crowded
- Equality and identity are different ideas
- Good keys need stable hashing behavior
