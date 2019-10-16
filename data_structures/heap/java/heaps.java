package lecture22;

import java.util.ArrayList;

public class heaps<k extends Comparable<k>, v> {
	private class node implements Comparable<node> {
		k score;
		v value;

		node(k score, v value) {
			this.score = score;
			this.value = value;
		}

		public String toString() {
			return "{" + this.score + ":" + this.value + "}";
		}

		@Override
		public int compareTo(heaps<k, v>.node o) {
			if (ismin) {
				return -1 * this.score.compareTo(o.score);
			} else {
				return this.score.compareTo(o.score);
			}
		}
	}

	private ArrayList<node> nodes;
	private boolean ismin;

	public heaps() {
		this(false);
	}

	public heaps(boolean ismin) {
		this.ismin = ismin;
		this.nodes = new ArrayList<>();
	}

	public int size() {
		return this.nodes.size();
	}

	public boolean isempty() {
		return this.nodes.size() == 0;
	}

	public void add(k score, v value) {
		node ntba = new node(score, value);
		this.nodes.add(ntba);
		this.upheapify(this.nodes.size() - 1);
	}

	private void upheapify(int ci) {
		if (ci == 0)
			return;
		int pi = (ci - 1) / 2;
		node parent = this.nodes.get(pi);
		node child = this.nodes.get(ci);
		if (parent.compareTo(child) < 0) {
			swap(pi, ci);
			upheapify(pi);
		}

	}

	public v removehp() {
		v rv = this.nodes.get(0).value;
		this.swap(0, this.nodes.size() - 1);
		this.nodes.remove(this.nodes.size() - 1);
		this.downheapify(0);
		return rv;
	}

	private void downheapify(int pi) {
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		int maxi = pi;

		if (lci < this.nodes.size() && this.nodes.get(lci).compareTo(this.nodes.get(maxi)) > 0)
			maxi = lci;
		if (rci < this.nodes.size() && this.nodes.get(rci).compareTo(this.nodes.get(maxi)) > 0)
			maxi = rci;
		if (maxi != pi) {
			this.swap(maxi, pi);
			this.downheapify(maxi);
		}
	}

	public v gethp() {
		return this.nodes.get(0).value;
	}

	public void display() {
		System.out.println(this);
	}

	public String toString() {
		return this.nodes.toString();
	}

	public void displaytree() {
		String ts = this.treestring(0);
		System.out.println(ts);
	}

	private String treestring(int pi) {
		String rv = "";
		int lci = 2 * pi + 1;
		int rci = 2 * pi + 2;
		if (lci < this.nodes.size()) {
			rv += this.nodes.get(lci) + "=>";
		} else {
			rv += "end =>";
		}
		rv += this.nodes.get(pi);
		if (rci < this.nodes.size()) {
			rv += "<=" + this.nodes.get(rci);
		} else {
			rv += "<= end";
		}
		rv += "\n";
		if (lci < this.nodes.size())
			rv += treestring(lci);
		if (rci < this.nodes.size())
			rv += treestring(rci);
		return rv;
	}

	private void swap(int i, int j) {
		node temp = this.nodes.get(i);
		this.nodes.set(i, this.nodes.get(j));
		this.nodes.set(j, temp);
	}

}
