### Topological Sort

Pertinent for DAGs, Directed Acyclic Graphs. DAGs are useful in the context of ETL pipelines in fields like data engineering. An example is software like Apache Airflow which is used for automating jobs on data.

Topological Sort yields a list of Nodes where for any nodes (X) have an edge to node (Y), node X appears before node Y in the list.

In 9.16.1 in zybooks, A does not have an edge to D, but D does have an edge to A, so D should appear before A in the list.

Algorithm:
