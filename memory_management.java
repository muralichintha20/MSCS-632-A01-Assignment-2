// Java: Memory Management via Garbage Collection
// Demonstrates: heap allocation, null reference for GC eligibility,
// memory usage tracking, and linked list lifecycle
//
// Note: Class is named Main to match the online compiler's filename requirement.
// In a local environment this would be saved as MemoryDemo.java with
// "public class MemoryDemo".

import java.util.ArrayList;
import java.util.List;

public class Main {

    static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

    // Demonstrates object lifecycle and GC eligibility
    public static void heapAllocationDemo() {
        System.out.println("--- Heap Allocation Demo ---");

        // Objects allocated on heap
        String s1 = new String("Hello");
        String s2 = new String("World");
        System.out.println("Created: " + s1 + " " + s2);

        // s1 now has no strong references — eligible for GC
        s1 = null;
        System.out.println("s1 set to null - eligible for garbage collection");

        // Suggest GC (not guaranteed to run immediately)
        System.gc();
        System.out.println("GC suggested");
    }

    // Demonstrates memory growth and reclamation with collections
    public static void collectionDemo() {
        System.out.println("\n--- Collection Demo ---");
        Runtime rt = Runtime.getRuntime();

        long before = rt.totalMemory() - rt.freeMemory();
        System.out.printf("Memory before allocation: %,d bytes%n", before);

        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < 1000; i++) {
            list.add(new int[1000]);   // allocate ~4KB each
        }

        long during = rt.totalMemory() - rt.freeMemory();
        System.out.printf("Memory during allocation:  %,d bytes%n", during);
        System.out.printf("Memory increase:           %,d bytes%n", during - before);

        list = null;   // remove strong reference — eligible for GC
        System.gc();
        System.runFinalization();

        long after = rt.totalMemory() - rt.freeMemory();
        System.out.printf("Memory after GC:           %,d bytes%n", after);
    }

    // Demonstrates linked list with no manual free required
    public static void linkedListDemo() {
        System.out.println("\n--- Linked List Demo ---");
        Node head = new Node(1);
        head.next = new Node(2);
        head.next.next = new Node(3);

        Node current = head;
        System.out.print("List: ");
        while (current != null) {
            System.out.print(current.value + " ");
            current = current.next;
        }
        System.out.println("\nList goes out of scope - GC will reclaim all nodes");
    }

    public static void main(String[] args) {
        heapAllocationDemo();
        collectionDemo();
        linkedListDemo();
        System.out.println("\nProgram complete. JVM manages all cleanup.");
    }
}
